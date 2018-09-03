
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;

struct zp
{
	int a, b;
} node[maxn * 4];

struct note
{
	int u, v, w, lca, next;
} edge[maxn * 4], edge1[maxn * 4];

int head[maxn * 4], ip, head1[maxn * 4], ip1;
int m, n;
int father[maxn * 4], vis[maxn * 4], dir[maxn * 4];

void init()
{
	memset(vis, 0, sizeof(vis));
	memset(dir, 0, sizeof(dir));
	memset(head, -1, sizeof(head));
	memset(head1, -1, sizeof(head1));
	ip = ip1 = 0;
}

void addEdge(int u, int v, int w)
{
	edge[ip].v = v, edge[ip].w = w, edge[ip].next = head[u], head[u] = ip++;
}

void addEdge1(int u, int v)
{
	edge1[ip1].u = u, edge1[ip1].v = v, edge1[ip1].lca = -1, edge1[ip1].next = head1[u], head1[u] = ip1++;
}

int Find(int x)
{
	if (father[x] == x)
		return x;
	return father[x] = Find(father[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x != y)
		father[y] = x;
}

void search(int u)
{
	vis[u] = 1;
	father[u] = u;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		int w = edge[i].w;
		if (!vis[v])
		{
			dir[v] = dir[u] + w;
			search(v);
			Union(u, v);
		}
	}
	for (int i = head1[u]; i != -1; i = edge1[i].next)
	{
		int v = edge1[i].v;
		if (vis[v])
		{
			edge1[i].lca = edge1[i ^ 1].lca = father[Find(v)];
		}
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		init();
		int root;
		for (int i = 0; i < n; i++) //建树
		{
			int a, b;
			cin >> a >> b;
			if (b == -1)
				root = a;
			else
				addEdge(b, a, 1);
		}
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) //离线查询建边
		{
			int a, b;
			cin >> a >> b;
			node[i].a = a;
			node[i].b = b;
			addEdge1(a, b);
			addEdge1(b, a);
		}
		dir[root] = 0;
		search(root);
		for (int i = 0; i < k * 2; i += 2)
		{
			int a = node[i / 2].a, b = node[i / 2].b;
			int tmp = edge1[i].lca;
			if (tmp == a)
				cout << "1" << endl;
			else if (tmp == b)
				cout << "2" << endl;
			else
				cout << "3" << endl;
		}
	}
	return 0;
}
