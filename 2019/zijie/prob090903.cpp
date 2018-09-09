
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>

using namespace std;

int ipCount = 0;

bool isIp(const string& number)
{
    if (number[0] == '0')   
        return number == "0";
    int num = stoi(number);;
    if (num > 0 && num <= 255)
        return true;
    else  
        return false;
}
// vector<string> strSplit(const string& str, char dem)
// {
//     vector<string> vs;
//     size_t start = 0;
//     while (start < str.size())
//     {
//         auto ret1 = str.find_first_of(dem);
//         vs.push_back(str.substr(start, ret1-start));
//         start = ret1;
//     }
//     return vs;
// }
vector<string> strSplit(string str, const string& pattern)
{
    vector<string> ret;
    size_t size = str.size();
    for (int i = 0; i < size; ++i)
    {
        auto pos = str.find(pattern, i);
        if (pos < size)
        {
            string sub = str.substr(i, pos - i);
            if (!sub.empty())
                ret.emplace_back(sub);
            i = pos + pattern.size() - 1;
        }
    }
    auto pos = str.find_last_of(pattern);
    if (pos < size)
    {
        string sub = str.substr(pos + 1);
        if (!sub.empty())
            ret.emplace_back(sub);
    }
    return ret;
}

void ipSplit(int start, int len, string str, string ip) 
{
    string back = ip;
    for (int i = 1; i < 4 && (start + i) <= len; i++) 
    {
        ip = back;
        string sub = str.substr(start, i);
        if (isIp(sub)) 
        {
            ip += sub;
            vector<string> strs = strSplit(ip, ".");
            if (strs.size() == 4 && (start + i) == len) {
                ++ipCount;
                return;
            }
            ip += ".";
            ipSplit(start + i, len, str, ip);
        }
    }
}

int main()
{
    string line = "";
    cin >> line;
    string ip = "";
    ipSplit(0, line.size(), line, ip);
    cout << ipCount << endl;
    return 0;
}
