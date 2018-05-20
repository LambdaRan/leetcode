
#include "noncopyable.h"

#include <iostream>

class x {};
class y : public virtual x {};
class z : public x 
{
    int mem_;
};


class A : noncopyable
{
    int a_;
};

int main()
{
    std::cout << sizeof(x) << std::endl;
    std::cout << sizeof(y) << std::endl;
    std::cout << sizeof(z) << std::endl;


    return 0;
}