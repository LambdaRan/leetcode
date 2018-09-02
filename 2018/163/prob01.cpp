

// 彩色砖块

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        bitset<27> bit;
        for (size_t i = 0; i < str.size(); ++i)
            bit.set(str[i]-'A');
        if (bit.count() > 2) 
            cout << 0 << endl;
        else 
            cout << bit.count() << endl;
    }
    return 0;
}
