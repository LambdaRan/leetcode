
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    long long result = 0;
    if (n == 1) result = 2;
    if (n == 2) result = 3;
    else  
    {
        long long one = 2;
        long long two = 3;
        for (int i = 2; i < n; ++i)
        {
            result = one + two;
            one = two;
            two = result;
        }
    }
    cout << result << endl;
    return 0;
}

