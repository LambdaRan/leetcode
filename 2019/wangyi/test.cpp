
#include <iostream>
#include <algorithm>
//#include <sstream>
#include <vector>
//#include <string>
#include <utility>
#include <map>

using namespace std;

int main()
{
    int nCap = 0; 
    size_t tTime = 0;
    cin >> nCap >> tTime;
    vector<int> everyPM(nCap);
    for (int i = 0; i < nCap; ++i)
        cin >> everyPM[i];

    std::map<int, size_t> valueCountMap;
    size_t maxLen = 0;
    valueCountMap[everyPM[nCap-1]] = 0;
    for (int i = nCap-2; i >= 0; --i)
    {
        if (everyPM[i] <= valueCountMap.rbegin()->first)
        {
            size_t mapSize = valueCountMap.size();
            valueCountMap[everyPM[i]] = mapSize;
        }
        else  
            valueCountMap[everyPM[i]] = 0;
        maxLen = std::max(maxLen, valueCountMap[everyPM[i]]);
    }
    if (maxLen < tTime)
        maxLen = maxLen + tTime - 1;
    else  
        maxLen = tTime;
    cout << maxLen << endl;
    return 0;
}

// 4 3
// 10 3 7 5
// 4