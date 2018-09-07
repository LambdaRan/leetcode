
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
    int nInter, kBettow, tCount;
    cin >> nInter >> kBettow >> tCount;
    vector<int> number(nInter);
    for (int i = 0; i < nInter; ++i)
    {
        cin >> number[i];
    }
    int maxCount = 0;
    map<int, int> keyValue;
    int start = 0;
    for (int i = 0; i < nInter; ++i)
    {
        if (i-start == kBettow)
        {
            for (auto it = keyValue.begin(); it != keyValue.end(); ++it)
            {
                if (it->second >= tCount)
                {
                    ++maxCount;
                    break;
                }
            }
            if (keyValue[number[start]] == 1)
                keyValue.erase(number[start]);
            else  
                --keyValue[number[start]];
            ++start;
        }

        ++keyValue[number[i]];
    }
    for (auto it = keyValue.begin(); it != keyValue.end(); ++it)
    {
        if (it->second >= tCount)
        {
            ++maxCount;
            break;
        }
    }
    cout << maxCount << endl;
    return 0;
}
