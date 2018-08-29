
#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 1e5 + 10;
struct node {
    int x, y;
}e[maxn], f[maxn];  //定义两个结构数组
int cnt[105];
int cmp(node a, node b)
{
    if(a.x ==b.x)
        return a.y >b.y;
    return a.x > b.x;
}
 
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d%d", &e[i].x, &e[i].y);
    for(int i=0; i<m; i++)
        scanf("%d%d", &f[i].x, &f[i].y);
    sort(e, e+n, cmp);
    sort(f, f+m, cmp);
    int num = 0;
    LL ans = 0;
    memset(cnt, 0, sizeof(cnt));
    int i,j,k;
    for(i=0,j=0; i<m; i++)
    {
        while(j<n && e[j].x >= f[i].x){
            cnt[e[j].y]++;
            j++;
        }
        for(k=0; k<=100; k++)
        {
            if(cnt[k] && k>=f[i].y)
            {
                num++;
                cnt[k]--;
                ans += 200*f[i].x + 3*f[i].y;
                break;
            }
        }
    }
    printf("%d %lld\n", num, ans);
    return 0;
}
