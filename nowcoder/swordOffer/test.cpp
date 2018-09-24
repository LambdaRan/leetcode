#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct A
{
    void fun()
    {
        cout << 1 << endl;
    }
};
struct B : A
{
    void fun()
    {
        cout << 2 << endl;
    }
};
int main()
{
    A a;
    B b;
    A* pa = &a;
    A& aa = b;

    pa->fun();
    aa.fun();
    return 0;
}   
