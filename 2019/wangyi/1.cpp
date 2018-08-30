
#include <iostream>
#include <algorithm>
//#include <sstream>
#include <vector>
//#include <string>
#include <utility>

using namespace std;

int main()
{
    int nCap = 0; 
    int tTime = 0;
    cin >> nCap >> tTime;
    vector<int> everyPM(nCap);
    for (int i = 0; i < nCap; ++i)
        cin >> everyPM[i];
    
    //typedef std::pair<int, int> GreateValueCount;
    //vector<GreateValueCount> valueCountMap(nCap);
    vector<int> valueCountMap(nCap);
    size_t curValueGreatCount = 0;

    for (auto it = everyPM.begin(); it != everyPM.end(); ++it)
    //for (size_t i = 0; i < everyPM.size(); ++i)
    {
        curValueGreatCount = std::count_if(std::next(it), everyPM.end(),
                                [&](const int value){
                                    return !(value < *it);
                                });
        valueCountMap[std::distance(everyPM.begin(), it)] = curValueGreatCount;
        //valueCountMap[std::distance(everyPM.begin(), it)] = std::make_pair(*it, curValueGreatCount);
    }

    int maxLength = 0;
    int curVlaue = 0;

    for (size_t i = 0; i < valueCountMap.size(); ++i)
    {
        if (valueCountMap[i].second < tTime)
            curVlaue = valueCountMap[i].second + tTime - 1;
        else  
            curVlaue = tTime;
        maxLength = std::max(maxLength, curVlaue);
    }
    cout << maxLength << endl;
    return 0;
}

// 4 3
// 10 3 7 5
// 4