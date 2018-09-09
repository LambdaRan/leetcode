


#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdlib>

#define MAX_V 100000
using namespace std;

vector<int>G[MAX_V];
int V,E,color[MAX_V];
bool dfs(int v,int c){
    color[v] = c;
    for(int i=0;i<G[v].size();i++)
    {
        if(color[G[v][i]] == c) return false;
        if(color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;
        
    }
    return true;
}
void solve()
{
    if(!dfs(0,1))
    {
        printf("NO\n");
        return;
    }

    printf("YES\n");
    return;
}


int main()
{
    int T;
    cin >> T;
    int tt = T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        memset(color,0,sizeof(color));
        memset(G,0,sizeof(G));
        int a,b;
        for(int i=0;i<E;i++)
        {
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        solve();
    }

    return 0;
}
