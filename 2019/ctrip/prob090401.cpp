

// 二进制中1的个数

#include <iostream>

using namespace std;

int main()
{
    long number;
    cin >> number;
    int count = 0;
    unsigned long flag = 1;
    while (flag)
    {
        if (n & flag)   
            ++count;
        flag = flag << 1;
    }
    cout << count << endl;
    return 0;
}