
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
// #include <sstream>
// #include <cctype>
//#include <stdio.h>
#include <map>

using namespace std;

struct Number
{
    string num;
    int val;
    int idx;
    Number(string s, int v, int index)
        : num(s), val(v), idx(index) {}
};
inline int transform(char c)
{
    if(c>='0'&&c<='9')
        return c-'0';
    else
        return c-'A'+10;
}
int trans(string str, int base)
{
    int result = 0;
    for(size_t i = 0; i < str.size(); ++i)
    {
        result *= base;
        result += transform(str[i]);
    }
    return result;
}
int main()
{
    string line;
    vector<Number> vec;
    map<int, int> valMap;
    int i = 0;
    while (cin >> line)
    {
        if (line == "END") break;
        auto pos = line.find('#');
        int base = stoi(line.substr(0, pos));
        int value = stoi(line.substr(pos+1), 0, base);
        vec.emplace_back(Number(line, value, i++));
        ++valMap[value];
    }
    bool isNone = true;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (valMap[vec[i].val] == 1)
        {
            cout << vec[i].num << endl;
            isNone = false;
        }
    }
    if (isNone)
        cout << "None" << endl;
    return 0;
}
