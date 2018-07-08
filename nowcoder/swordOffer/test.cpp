#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    std::cout << std::numeric_limits<int>::max() << std::endl;
    std::cout << std::numeric_limits<int>::max_digits10 << std::endl;
    std::cout << std::numeric_limits<int>::digits10 << std::endl;
}
