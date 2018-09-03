
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

const int c = 100010;

struct node
{
	long x;
	long h;
	int len;
	int i;
}p[c];
int dp[c];

bool cmp(node nd1,node nd2)
{
	return nd1.x < nd2.x;
}

void fun(int n)
{
	node nd;
	stack<node> st;
	st.push(p[1]);
	for(int i = 2; i <= n; i ++)
	{
		while(!st.empty() && (st.top().x + st.top().h -1) < p[i].x)
		{
			nd = st.top();
			st.pop();
			dp[nd.i] = p[i].len - nd.len;
		}
		st.push(p[i]);
	}
}

int main()
{

       int n, i, j;
	while(cin >> n)
	{
		for(i = 1; i <= n; i ++)
		{
			//scanf("%I64d%d",&p[i].x,&p[i].h);
            cin >> p[i].x >> p[i].h;
		    p[i].i = i;
		}
        n ++;
		p[n].x = (1 << 30);
		sort(p+1,p+1+n,cmp);
		for(i = 1; i <= n; i ++)
			p[i].len = i;
		fun(n);
		for(i = 1; i < n; i ++)
		{
			if(i != 1) 
                cout << " ";
			//printf("%d",dp[i]);
            cout << dp[i];
		}
		//printf("\n");
        cout << "\n";
	}
	return 0;
}

