
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
//#include <stdio.h>

using namespace std;

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
    string line;
    int num;
    cin >> num;
    char endd;
    cin >> endd;
    for (int i = 0; i < num; ++i)
    {
        getline(cin, line);
        vector<int> ret = strSplit(line, ' ');
        cout << "size: " << ret.size() << endl;
    }

    return 0;
}
