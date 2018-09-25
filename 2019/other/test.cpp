
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    cout << "Hello world" << endl;
    double darr[2] = {4, 8}, *p , *q;
    p = &darr[0];
    q = p + 1;
    cout << (q-p) << endl;
    cout << ((int)q - (int)p) << endl;
    // char* sz = "0123456789";
    // int *p = (int*)sz;
    // printf("%x\n", *++p);
    return 0;
}
