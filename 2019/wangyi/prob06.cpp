

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    int nTower = 0;
    int kOper = 0;
    cin >> nTower >> kOper;
    vector<int> everHeight(nTower);
    for (int i = 0; i < nTower; ++i)
        cin >> everHeight[i];
    

    long sumHeight = std::accumulate(everHeight.begin(), everHeight.end(), 0);
    int remain = static_cast<int>(sumHeight % nTower);
    int average = static_cast<int>(sumHeight / nTower);
    if (remain != 0)
        average += 1;
    vector<int> diff(nTower);  
    for (int i = 0; i < nTower; ++i)
    {
        if (everHeight[i] < average)
            diff[i] = average - everHeight[i];
    }
    int sumDiff = std::accumulate(diff.begin(), diff.end(), 0);

    if (sumDiff <= kOper) // 操作次数够用
    {
        if (remain == 0) // 能够一样高
        {
            cout << 0 << " " << sumDiff << endl;
            size_t greAveIndex = 0;
            size_t lessAveIndex = 0;
            while (sumDiff > 0)
            {
                auto gret = std::find_if(std::next(everHeight.begin(), greAveIndex), everHeight.end(), 
                [average](const int value){
                    return value > average;
                });
                greAveIndex = std::distance(everHeight.begin(), gret);

                auto lret = std::find_if(std::next(everHeight.begin(), lessAveIndex), everHeight.end(),
                [average](const int value){
                    return value < average;
                });
                lessAveIndex = std::distance(everHeight.begin(), lret);

                int curDiff = everHeight[greAveIndex] - average;
                if (curDiff > diff[lessAveIndex])
                {
                    for (int i = diff[lessAveIndex]; i > 0; --i)
                        cout << (greAveIndex+1) << " " << (lessAveIndex+1) << endl;
                    everHeight[lessAveIndex] = average;
                    everHeight[greAveIndex] -= diff[lessAveIndex];
                    sumDiff -= diff[lessAveIndex];
                }
                else  
                {
                    for (int i = curDiff; i > 0; --i)
                        cout << (greAveIndex+1) << " " << (lessAveIndex+1) << endl;
                    everHeight[lessAveIndex] += curDiff;
                    everHeight[greAveIndex] = average;
                    sumDiff -= curDiff;
                }
            }
        } // 能够一样高

        
    }

    return 0;
}
