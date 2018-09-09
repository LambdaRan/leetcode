
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
//#include <stdio.h>


using namespace std;

int main()
{
    string line = "";
    cin >> line;
    int maxLength = 0;
    int start = -1;
    unordered_map<char, int> letterMap;
    
    for (int i = 0; i < line.size(); ++i)
    {
        if (letterMap.count(line[i]) != 0)
            start = max(start, letterMap[line[i]]);
        letterMap[line[i]] = i;
        maxLength = max(maxLength, i - start);
    }
    cout << maxLength << endl;
    return 0;
}
