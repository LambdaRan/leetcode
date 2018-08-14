

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <iterator>

using namespace std;

// 青蛙过河
// https://www.cnblogs.com/InWILL/p/7358318.html

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=1E6;
const int MAXM=105;
const int MOD=100;

int l,s,t,m,ans=0x7fffffff;
int M[MAXM],F[MAXN];
bool stone[MAXN];

int main()
{
    memset(F,0x7f,sizeof(F));
    F[0]=0;
    scanf("%d",&l);
    scanf("%d %d %d",&s,&t,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&M[i]);
    sort(M+1,M+m+1);
    if(s==t)
    {
        ans=0;
        for(int i=1;i<=m;i++)
            if(M[i]%s==0)
                ans++;
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        int x=M[i]-M[i-1];
        M[i]=M[i-1]+x%MOD;
        stone[M[i]]=1;
    }
    for(int i=1;i<=M[m]+t;i++)
    {
        for(int j=s;j<=t;j++)
            if(i-j>=0)
                F[i]=min(F[i],F[i-j]);
        if(stone[i]) F[i]++;
    }
    for(int i=M[m];i<=M[m]+t;i++)
        ans=min(ans,F[i]);
    cout<<ans<<endl;
    return 0;
}