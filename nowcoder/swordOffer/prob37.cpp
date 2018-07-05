
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

/*
* Name: 数字在排序数组中出现的次数
* Description: 统计一个数字在排序数组中出现的次数。
*
*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        
        typedef std::pair<std::vector<int>::iterator, std::vector<int>::iterator> RetTypePair;
        RetTypePair ret = std::equal_range(data.begin(), data.end(), k);
        return static_cast<int>(ret.second - ret.first);
    }
};

int main() 
{
    Solution s;

    vector<int> vec = {1,1,1,1,1,3,3,3,3,3,3,6,7,8,8};
    std::cout << "method 1: \n";
    std::cout << "1 : " << s.GetNumberOfK(vec, 6);
    std::cout << std::endl;
    return 0;
}
