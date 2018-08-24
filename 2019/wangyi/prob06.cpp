

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <utility>

using namespace std;

// 塔 立方体

int main()
{
    int nTower = 0;
    int kOper = 0;
    cin >> nTower >> kOper;
    vector<int> everHeight(nTower);
    for (int i = 0; i < nTower; ++i)
        cin >> everHeight[i];
    
    int count = 0;
    typedef std::pair<int, int> FromTo;
    vector<FromTo> movePath;
    while (count < kOper)
    {
        auto minIter = std::min_element(everHeight.begin(), everHeight.end());
        auto maxIter = std::max_element(everHeight.begin(), everHeight.end());
        if (*maxIter - *minIter > 1)
        {
            --(*maxIter);
            ++(*minIter);
            FromTo fromTo = std::make_pair(std::distance(everHeight.begin(), maxIter)+1,
                            std::distance(everHeight.begin(), minIter)+1);
            movePath.push_back(fromTo);
            ++count;
        }
        else  
            break;
    }
    auto minIter = std::min_element(everHeight.begin(), everHeight.end());
    auto maxIter = std::max_element(everHeight.begin(), everHeight.end());
    cout << (*maxIter - *minIter) << " " << count << endl;
    for (size_t i = 0; i < movePath.size(); ++i)
    {
        cout << movePath[i].first << " " << movePath[i].second << '\n';
    }
    cout << endl;

    return 0;
}
