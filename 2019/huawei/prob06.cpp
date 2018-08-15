
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <functional>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        size_t first = 0;
        size_t second = 0;
        typedef std::pair<size_t, string> ValueType;
        auto comp = [](const ValueType& a, const ValueType& b) {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        multiset<ValueType, decltype(comp)> allStr(comp);
        for (second  = 1; second < line.size(); ++second)
        {
            if (line[first] != line[second])
            {
                allStr.insert(make_pair(second-first, line.substr(first, second-first)));
                first = second;
            }
        }
        if (first < second)
            allStr.insert(make_pair(second-first, line.substr(first)));

        // std::for_each(allStr.begin(), allStr.end(), [](const ValueType& value){
        //     cout << value.second << " ";
        // });
        // cout << endl;
        cout << allStr.begin()->second << endl;
    }

    return 0;
}