
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
// #include <sstream>
// #include <cctype>
//#include <stdio.h>
#include <unordered_map>

using namespace std;

int maxValue(vector<int>& v) 
{
    int mleft = 0, mright = v.size() - 1;
    int res = 0;
    int maxl = 0, maxmRight = 0;
    while (mleft <= mright)
    {
        if (v[mleft] <= v[mright])
        {
            if (v[mleft] >= maxl)
                maxl = v[mleft];
            else
                res += maxl - v[mleft];
            ++mleft; 
        }
        else
        {
            if (v[mright] >= maxmRight)
                maxmRight = v[mright];
            else
                res += maxmRight - v[mright];
            --mright;
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    int m;
    cin >> m;
    int result = -1;
    for (int i = 0; i < v.size(); ++i)
    {
        v[i] += m;
        result = max(result, maxArea(v));
        v[i] -= m;
    }
    cout << result << endl;
    return 0;
}

