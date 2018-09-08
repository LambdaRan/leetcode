#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>

using namespace std;

int main()
{
    long n, m;  
    cin >> n >> m;

    vector<long> lev(n + 1, 0);
    vector<long> V(n + 1, 0);

    for (int i = 1; i <= n; ++i)
        cin >> V[i];

    for (int i = 1; i <= m; ++i)
    {
        int op, level, vol;
        cin >> op;
        if (op == 2)
            cin >> level >> vol;
        else
            cin >> level;
        if (op == 2)
        {
            while (vol)
            {
                int avail = V[level] - lev[level];
                if (vol > avail)
                {
                    lev[level] += avail;
                    vol -= avail;
                    level++;
                    if (level == n)
                        break;
                }
                else
                {
                    lev[level] += vol;
                    break;
                }
            }
        }
        else
            cout << lev[level] << endl;

    }
    return 0;
}
