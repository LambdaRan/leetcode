
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdlib>
#define MAX_V 100000
using namespace std;
vector<int>G[MAX_V];//这里用不定长数组，来存图。 
int V,E,color[MAX_V];
bool dfs(int v,int c){
    color[v] = c;
    for(int i=0;i<G[v].size();i++){//连接这个节点的所有节点 
        if(color[G[v][i]] == c) return false;
        if(color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;
        /*注意这一步，不能分解，因为当该层的下一层，返回false时，到递归回到这一层仍要返回false。*/ 
    }
    return true;
}
void solve()
{
    if(!dfs(0,1)){//本题是从0这个节点来搜索就可，但有些题目，图可能不是联通的，故要从头到尾遍历一遍。 
        printf("NO\n");
        return;
    }

    printf("YES\n");
    return;
}
int main(void)
{
    while(~scanf("%d",&V)){
        scanf("%d",&E);
        memset(color,0,sizeof(color));
        memset(G,0,sizeof(G));
        int a,b;
        for(int i=0;i<E;i++)
        {
            scanf("%d %d",&a,&b);//这里是无向图，要存存两次，本人就在这里WA了好多次，惭愧，一定细心。 
            G[a].push_back(b);
            G[b].push_back(a);
        }
        solve();
    }
    return 0;
}