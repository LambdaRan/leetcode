

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

size_t sticker(std::vector<int>& vec)
{
    if (vec.empty()) return 0;
    if (vec.size() == 1) return 1;
    size_t sum = vec.size();
    for (int i = 1; i < vec.size()-1; ++i)
    {
        if (vec[i] > vec[i-1])
            ++sum;
        if (vec[i] > vec[i+1])
            ++sum;
    }
    if (vec[vec.size()-1] > vec[vec.size()-2])
        ++sum;
    return sum;
}
int main()
{
    std::vector<int> vec = {2,4,5,2,3,7};
    std::cout << sticker(vec) << std::endl;
    return 0;
}