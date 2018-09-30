

#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>

//#include <stdio.h>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    map<int, int> numMap;
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        ++numMap[tmp];
    }
    int maxR = 0;
    for (auto it = numMap.begin(); it != numMap.end(); ++it)
    {
        maxR = max(maxR, it->second);
    }
    cout << maxR << endl;
    return 0;
}

