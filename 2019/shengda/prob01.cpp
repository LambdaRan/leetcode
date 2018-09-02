

#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>

using namespace std;

int number(char ch1, char ch2)
{
    return (ch1-'0')*10 + (ch2-'0');
}
int maxCount(const string& str)
{
    if (str.size() <= 1)
        return str.size();
    if (str.size() == 2)
    {
        int x = number(str[0], str[1]);
        if (x <= 26) return 2;
        else return 1;
    }
    int y = number(str[str.size()-2], str[str.size()-1]);
    if (y <= 26)
        return maxCount(str.substr(0, str.size()-1)) + maxCount(str.substr(0, str.size()-2));
    else  
        return maxCount(str.substr(0, str.size()-1));
}
int maxCount(const string& str)
{
    if (str.size() <= 1)
        return str.size();

    vector<int> old(str.size(), 0);
    old[0] = 1;
    old[1] = number(str[0], str[1]) <= 26 ? 2 : 1;
    for (size_t i = 2; i < str.size(); ++i)
    {
        if (number(str[i-1], str[i]) <= 26)
            old[i] = old[i-1] + [i-2];
        else  
            old[i] = old[i-1];
    }
    return old.back();
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << maxCount(line) << endl;
    }

    return 0;
}

