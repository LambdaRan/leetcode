
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <vector>
#include <string>

#include <stdio.h>

using namespace std;

// https://blog.csdn.net/arrowlll/article/details/52629448
// 小Q的歌单

long long c[105][105];
const int mod = 1000000007;
// 计算组合数
void init()
{
    c[0][0] = 1;
    for (int i = 1; i <= 100; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= 100; ++j)
        {
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
        }
        
    }
}

int main()
{
    int k, a, x, b, y;
    scanf("%d", &k);
    scanf("%d%d%d%d", &a, &x, &b, &y);
    init();
    long long ans = 0;
    for (int i = 0; i <= x; ++i)
    {
        if (i*a <= k && (k-a*i)%b==0 && (k-a*i)/b<=y)
            ans = (ans + (c[x][i]*c[y][(k-a*i)/b])%mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
