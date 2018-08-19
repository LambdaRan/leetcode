

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

int main()
{
    int mSocity = 0;
    cin >> mSocity;
    typedef std::pair<int, int> TimeEntity;
    vector<TimeEntity> peerSocityTime(mSocity);
    { // 输入
        int start = 0;
        int end = 0;
        for (int i = 0; i < mSocity; ++i)
        {
            cin >> start >> end;
            peerSocityTime[i] = make_pair(start, end);
        }
    }
    int conflictCount = 0;
    int whichOne = 0;
    set<TimeEntity> checkSet;
    //map<int, int> checkMap;
    for (size_t i = 0; i < mSocity; ++i)
    {
        auto ret = checkSet.lower_bound(peerSocityTime[i]);
        if (ret != checkSet.end())
        {
            if (peerSocityTime[i].first >= ret->first && peerSocityTime[i].first <= ret->second)
            {
                ++conflictCount;
                whichOne = i;
            }
            if (conflictCount >= 2)
                break;
        }
        checkSet.insert(peerSocityTime[i]);
    }

    if (conflictCount == 0)
    {
        for (int i = 0; i < mSocity; ++i)
            cout << (i+1) << " ";
        cout << endl;
    }
    if (conflictCount == 1)
    {
        cout << conflictCount << '\n';
        cout << whichOne << endl;
    }
    if (conflictCount >= 2)
    {
        cout << 0 << endl;
    }
    return 0;
}
