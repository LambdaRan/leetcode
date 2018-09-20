

#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

#include <map>
#include <set>
#include <deque>
#include <unordered_set>

//#include <stdio.h>
using namespace std;


void calcPrev(int point, map<int, vector<int>>& prev, size_t& result)
{
    vector<int> prep = prev[point];
    result += prep.size();
    // for (size_t i = 0; i < prep.size(); ++i)
    // {
    //     calcPrev(prep[i], prev, result);
    // }
    unordered_set<int> que(prep.begin(), prep.end());

    while (!que.empty())
    {
        int ret = *que.begin();
        que.erase(que.begin());
        result += prev[ret].size();
        //que.insert(que.end(), prev[ret].begin(), prev[ret].end());
        
    }
}

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;

    map<int, vector<int>> back;
    map<int, vector<int>> prev;
    set<int> point;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        back[u].push_back(v);
        prev[v].push_back(u);
        point.insert(u);
        point.insert(v);
    }
    int maxCity = 0;
    for (auto it = point.begin(); it != point.end(); ++it)
    {
        size_t curOut = back[*it].size();
        size_t curIn = 0;
        calcPrev(*it, prev, curIn);
        if (curIn > curOut)
            ++maxCity;
    }
    cout << maxCity << endl;
    return 0;
}

