
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <iterator>
#include <string>
#include <map>
//#include <stdio.h>
#include <sstream>
#include <cctype>
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
    int numCustomer;
    int numProduct;
    int numK;
    cin >> numCustomer;
    cin >> numProduct;
    cin >> numK;

    map<int, vector<int> > idMap;
    for (int i = 0; i < numCustomer; ++i)
    {
        vector<int> ret(numProduct);
        for (int j = 0; j < numProduct; ++j)
            cin >> ret[j];

        for (int v : ret)
        {
            idMap[v].push_back(i);
        }
    }

    vector<int> result;
    for (auto it = idMap.begin(); it != idMap.end(); ++it)
    {
        if (it->second.size() >= numK)
            result.push_back(it->first);
    }
    cout << (result.size()) << endl;
    sort(result.begin(), result.end());
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
