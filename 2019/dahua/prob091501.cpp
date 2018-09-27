
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
// #include <sstream>
// #include <cctype>
#include <stdio.h>

using namespace std;

int func(int x)
{
    int constx = 0;
    while(x)
    {
        constx++;
        x = x & (x-1);
    }
    return constx;
}
int main()
{
    printf("%d.\n", func(9999));

    return 0;
}
