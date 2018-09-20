
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

void calculate(int l, int cur, int x, int y, int z, int& result);

int main()
{
    int mp, mq, mr;
    cin >> mp >> mq >> mr;
    int result = 0;
    calculate(mr, 0, mp, mq, mr, result);
    cout << result << endl;
    return 0;
}

void calculate(int l, int cur, int x, int y, int z, int& result)
{
    if (l == cur) return;
    if (x == 0 && y == 0 && z == 0)
    {
        ++result;
        return;
    }
    if (x > 0)
        calculate(cur, 1, x - 1, y, z, result);
    if (y > 0)
        calculate(cur, 2, x, y - 1, z, result);
    if (z > 0)
        calculate(cur, 3, x, y, z - 1, result);
}