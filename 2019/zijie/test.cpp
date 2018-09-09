#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> strSplit(const string& str, char dem)
{
    vector<string> vs;
    size_t start = 0;
    size_t size = str.size();
    while (start < size)
    {
        auto ret = str.find_first_of(dem, start);
        ret = (ret == string::npos) ? size : ret;
        vs.emplace_back(str.substr(start, ret-start));
        start = ret + 1;
    }
    return vs;
}
// #include <sstream>
// #include <cctype>
vector<int> strSplit(string input, char delim) 
{
    vector<int> output;
    // trimLeftTrailingSpaces(input);
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
    // trimRightTrailingSpaces(input);
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
    //input = input.substr(1, input.length() - 2);
    istringstream ss(input);
    // ss.str(input);
    string item;
    // char delim = ',';
    while (getline(ss, item, delim)) {
        output.emplace_back(stoi(item));
    }
    return output;
}

int main()
{
   cout << "Hello World" << endl; 
   string line = "192.168.1.254";
   vector<string> ret = strSplit(line, '.');
   cout << ret.size() << endl;
   for (auto s : ret)
        cout << s << "\n";
    vector<int> ret1 = strSplit(line, '.');
    for (auto v : ret1)
        cout << v << "\n";
   return 0;
}