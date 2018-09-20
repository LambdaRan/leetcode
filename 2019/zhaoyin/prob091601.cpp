
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
    getline(cin, line);
    vector<int> ggi = strSplit(line, ' ');
    getline(cin, line);
    vector<int> ssi = strSplit(line, ' ');

    sort(ggi.begin(), ggi.end());
    sort(ssi.begin(), ssi.end());
    int maxCount = 0;
    for (size_t i = 0; i < ggi.size(); ++i)
    {
        int tmp = ggi[i];
        auto ret = find_if(ssi.begin(), ssi.end(), [tmp](const int v){
            return v >= tmp;
        });
        if (ret != ssi.end())
        {
            ++maxCount;
            ssi.erase(ret);
        }
        else 
            break;
    }
    cout << maxCount << endl;
    return 0;
}
