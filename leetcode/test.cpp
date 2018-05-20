
#include <iostream>
#include <string>
#include <cstdint>

int main()
{


    int num1 = INT32_MIN;
    int num2 = INT32_MAX;

    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;

    std::string istr1 = std::to_string(num1);
    std::string istr2 = std::to_string(num2);

    std::cout << "istr1: " << istr1 << " istr2: " << istr2 << std::endl;

    return 0;
}