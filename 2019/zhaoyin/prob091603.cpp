
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int intput;
    cin >> intput;
    int count = 0;
    for (int i = 1; i <= intput; ++i)
    {
        string str = to_string(i);
        if (str.find("3") != string::npos || 
            str.find("4") != string::npos || 
            str.find("7") != string::npos)
            continue;
        if (str.find("2") != string::npos || 
            str.find("5") != string::npos || 
            str.find("6") != string::npos || 
            str.find("9") != string::npos)
            ++count;
    }

    cout << count << endl;
    return 0;
}


