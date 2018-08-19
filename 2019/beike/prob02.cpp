

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

std::map<char, int> numMap = {
    {'A', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'T', 10},
    {'J', 11},
    {'Q', 12},
    {'K', 13}
};
int main()
{
    int result = 0;
    string line;
    while (getline(cin, line))
    {
        vector<int> numCount(14);
        for (char ch : line)
            ++numCount[numMap[ch]];

        { // 找顺子
            int count = 0;
            int prevNum = 0;
            int start = 1;
            for (int i = start; i < 14; ++i)
            {
                if (numCount[i] > 0 && i - prevNum == 1)
                {
                    ++count;
                    if (count == 5)
                    {
                        for (int j = start; j <= i; ++j)
                        {
                            --numCount[j];
                        }
                        count = 0;
                        prevNum = 0;
                        start = 1;
                        i = start;
                        ++result;
                    }
                }
                else  
                {
                    if (count < 5)
                    {
                        count = 0;
                        start = i;
                        prevNum = i;
                    }
                }
            }
        }

        { // 四带二
            for (int i = 1; i < 14; ++i)
            {
                if (numCount[i] == 4)
                {
                    int one = 0;
                    int two = 0;
                    for (int j = 1; j < 14; ++j)
                    {
                        if (numCount[j] == 2)
                        {
                            two = j;
                        }
                        if (numCount[j] == 1)
                        {
                            one = j;
                        }
                    }
                    if (two > 0)
                    {
                        numCount[i] = numCount[i] - 4;
                        numCount[two] = numCount[two] - 2;
                        ++result;
                        continue;
                    }
                    if (one > 0)
                    {
                        numCount[i] = numCount[i] - 4;
                        numCount[one] = numCount[one] - 1;
                        ++result;
                        continue;
                    }
                    numCount[i] = numCount[i] - 4;
                    ++result;
                }
            }
        } // 四

        { // 三带一
            for (int i = 1; i < 14; ++i)
            {
                if (numCount[i] == 3)
                {
                    int one = 0;
                    for (int j = 1; j < 14; ++j)
                    {
                        if (numCount[j] == 1)
                        {
                            one = j;
                        }
                    }
                    if (one > 0)
                    {
                        numCount[i] = numCount[i] - 3;
                        --numCount[one];
                        ++result;
                        continue;
                    }
                    numCount[i] = numCount[i] - 3;
                    ++result;
                }
            }
        } // 三

        { // 对子
            for (int i = 1; i < 14; ++i)
            {
                if (numCount[i] == 2)
                {
                    numCount[i] = numCount[i] - 2;
                    ++result;
                }
            } 
        }

        for (int i = 1; i < 14; ++i)
        {
            if (numCount[i] == 1)
            {
                ++result;
            }
        } 

        cout << result << endl;

    }

    return 0;
}

// 8K67A65K27T59K346AK2
// 4