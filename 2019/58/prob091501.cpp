


#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int func(int n)
{
    if (n <= 2) return n;
    if (n == 3) return 4;
    int one = 1;
    int two = 2;
    int three = 4;
    int result = 0;
    for (int i = 4; i <= n; ++i)
    {
        result = one + two + three;
        one = two;
        two = three;
        three = result;
    }
    return result;
}

    int jumpFloor(int number) {
        if (number == 1) return 1;
        if (number == 2) return 2;
        if (number == 3) return 4;
        return jumpFloor(number-1) + jumpFloor(number-2) + jumpFloor(number-3);
    }

int main()
{
    int n = 0;

        int a[5] = {1,2,3,4,5};
        int* ptr = (int*)(&a+1);
        cout << *(a+1) << *(ptr-1) << endl;
    
    return 0;
}
