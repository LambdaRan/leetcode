

// https://blog.csdn.net/u011345136/article/details/25889119

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
    int nDuo = 0;
    cin >> nDuo;
    int xLoca = 0;
    int hHigh = 0;
    typedef std::pair<int, int> LH;
    typedef std::pair<LH, int> Entry;
    vector<Entry> localHigh;
    for (int i = 0; i < nDuo; ++i)
    {
        cin >> xLoca >> hHigh;
        localHigh.push_back(make_pair(make_pair(xLoca, hHigh), i));
    }
    std::sort(localHigh.begin(), localHigh.end(),[](const Entry& ent){
        return ent.first.first < ent.first.first;
    });

    for (int i = 0; i < nDuo; ++i)
    {
        auto ret = find_if(localHigh.begin(), localHigh.end(), [=](const Entry& ent){
            return ent.second == i;
        });

    }
    return 0;
}

