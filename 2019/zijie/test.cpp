#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int coun = 0;

int func(int i)
{
    ++coun;
    if (i == 0) return 0;
    else if (i == 1) return 2;
    else return func(i-1) + func(i-2);
}

int main()
{
    func(10);
    cout << coun << endl;
    int arr[] = {25, 42};
    int *p = arr;
    cout << (++*p) << endl;
   return 0;
}