
#include <algorithm>
#include <map>
#include <iostream>
//#include <cstdio.h>


int main()
{
    string line = "";
    cin >> line;
    
    int nTable = 0;
    scanf("%d", &nTable);
    typedef pair<string, long long> Entry;
    vector<Entry> table(nTable);
    string word = ""; 
    int tidx= 0;
    while (nTable--)
    {
       cin >> word;
       long long value = pow(word.size(), 2);
       table[tidx++] = make_pair(word, value);
    }
    int lineIdx = 0;
    vector<int> tabIdxV;
    int curIdx = 0;
    for (int i = 0; i < tidex; ++i)
    {
        if (line[lineIdx] == table[i].first[0])
        {
            if (table[i].second > table[curIdx].second)
                curIdx = i;
        }
        else 
        {
            tabIdxV.push_back(curIdx); 
            lineIdx = table[curIdex].first.size();
            curIdx = i;
        }
    }
    for (size_t v = 0; v < tabIdxV.size()-1; ++v)
    {
        cout << table[v].first << " ";
    }
    cout << table.back().first;
    return 0;
}