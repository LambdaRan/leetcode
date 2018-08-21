
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int nCourtTime = 0;
    int kStillTime = 0;
    cin >> nCourtTime >> kStillTime;
    vector<int> aInterestWeight(nCourtTime);
    for (int i = 0; i < nCourtTime; ++i)
    {
        cin >> aInterestWeight[i];
    }
    vector<int> isAwake(nCourtTime);
    for (int i = 0 ; i < nCourtTime; ++i)
    {
        cin >> isAwake[i];
    }
    long curSumInterestWeight = 0;
    for (int i = 0; i < nCourtTime; ++i)
    {
        if (isAwake[i])
            curSumInterestWeight += aInterestWeight[i];
    }
    int start = 0; 
    int second = 0;
    int partWeightSum = 0;
    int maxPartWeight = 0;
    while (second < nCourtTime)
    {
        if (second - start == kStillTime) 
        {
            if (!isAwake[start])
                partWeightSum -= aInterestWeight[start];
            ++start;
        }
        if (!isAwake[second])
            partWeightSum += aInterestWeight[second];
        ++second;
        maxPartWeight = max(maxPartWeight, partWeightSum);
    }
    cout << (curSumInterestWeight + maxPartWeight) << endl;
    return 0;
}
// 方法二：找0 后面三个数相加找最大

// 6 3
// 1 3 5 2 5 4
// 1 1 0 1 0 0

// 16
