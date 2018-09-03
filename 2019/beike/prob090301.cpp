
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
    int nFamily = 0;
    cin >> nFamily;
    int aFirst = 0;
    int bSecond = 0;
    typedef std::pair<int, int> Entry;
    vector<Entry> relaFamily;
    for (int i = 0; i < nFamily; ++i)
    {
        cin >> aFirst >> bSecond;
        relaFamily.push_back(make_pair(aFirst, bSecond));
    }
    int mAsk = 0;
    cin >> mAsk;
    vector<Entry> askFamily;
    for (int i = 0; i < mAsk; ++i)
    {
        cin >> aFirst >> bSecond;
        askFamily.push_back(make_pair(aFirst, bSecond));
    }

    
    

    return 0;
}

