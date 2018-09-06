
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <set>

#include <ctype.h>

//#include <stdio.h>

using namespace std;

string entity(string str, int count)
{
    string result = "";
    for (int i = 0; i < count; ++i)
    {
        result += str; 
    }
    return result;
}

int main()
{
    string line = "";
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string number = "0123456789";
    typedef pair<int, string> Entry;
    while (getline(cin, line))
    {
        set<Entry> letterSet;
        size_t start = 0;
        while (start < line.size())
        {
            auto ret1 = line.find_first_not_of(alpha, start);
            string letter = string(line, start, ret1-start);
            auto ret2 = line.find_first_not_of(number, ret1);
            int size = stoi(string(line, ret1, ret2-ret1));
            letterSet.insert(make_pair(size, letter));
            start = ret2;
        }
        string result = "";
        for (auto it = letterSet.begin(); it != letterSet.end(); ++it)
        {
            //cout << it->first << " " << it->second << endl;
            result += entity(it->second, it->first);
        }
        cout << result << endl;
    }

    return 0;
}
