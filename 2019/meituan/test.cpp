
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>

class A {};
class B {};

class C : public A 
{
public: 
    int c_;
};
class D : public A, public B 
{
public: 
    int d_;
};
class E 
{
public: 
    int e;
    A a;
    // B b;
};

using namespace std;

int main()
{
    cout << "EBO" << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    cout << sizeof(E) << endl;
    return 0;
}
