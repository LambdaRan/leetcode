

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main()
{

    vector<int> vec;
    string line;
    getline(std::cin, line);
    std::istringstream allNumber(line);
    int number = 0;
    while (allNumber >> number) 
        vec.push_back(number);

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}