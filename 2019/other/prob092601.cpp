
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
using namespace std;

vector<int> splitInteger(long val)
{
    vector<int> result;
    int remain = 0;
    const int kBase = 10;
    while (val)
    {
        remain = val % kBase;
        val /= kBase;
        result.emplace_back(remain);
    }
    return result;
}

int main()
{
    int count = 0;
    cin >> count;
    vector<long> input;
    long tmp;
    while (count--)
    {
        cin >> tmp;
        input.emplace_back(tmp);
    }

    for (long lv : input)
    {
        vector<int> ret = splitInteger(lv);
        bool isH = false;
        bool isS = true;
        bool isG = true;
        for (int iv : ret)
        {
            if (lv % iv == 0)
            {
                isH = true;
                isS = false;
            }
            else  
                isG = false;
        }
        if (!isG && isH)
            cout << "H\n";
        else if (isS)
            cout << "S\n";
        else if(isG)
        {
            cout << "G\n";
        }
    }

    return 0;
}
