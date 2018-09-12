

#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;

int gcd(int x, int y) 
{
    if(y == 0) return x;
    return gcd(y, x % y);
}
int main() 
{
    int n;
    while(scanf("%d", &n) != EOF) 
    {
        int limit = (int)floor(sqrt(n));
        int cnt = 0;
        ll a, b, c;
        for(int s = 1; s <= limit; s++)
        {
            for(int r = s+1; r <= limit; r += 2) 
            {
                c = r*r + s*s;
                if(gcd(r,s) == 1 && c <= n) 
                {
                    // a = r*r - s*s;
                    // b = 2*r*s;
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}