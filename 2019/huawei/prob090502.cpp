

#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <set>

//#include <stdio.h>


using namespace std;

int main()
{
    string str1 = "";
    string str2 = "";
    while (cin >> str1 >> str2)
    {
        vector<int> alpha(26);
        for (char ch : str1)
        {
            ++alpha[ch-'A'];
        }
        bool isAll = true;
        for (char ch : str2)
        {
            if (alpha[ch-'A'] == 0)
            {
                isAll = false;
                break;
            }
        }
        // set<char> str1Set;
        // for (char ch : str1)
        //     str1Set.insert(ch);
        // bool isAll = true;
        // for (char ch : str2)
        // {
        //     auto ret = str1Set.find(ch);
        //     if (ret == str1Set.end())
        //     {
        //         isAll = false;
        //         break;
        //     }
        // }
        if (isAll)
            cout << "true" << endl;
        else  
            cout << "false" << endl;
    }

    return 0;
}

