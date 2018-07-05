
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
    // //使用STL算法count 循序查找O(n)
    // int GetNumberOfK(vector<int> data, int k) {
    //     return count(data.begin(), data.end(), k);
    // }
    // //利用STL的multimap容器底层以红黑树为基础,构造成本O(n),查询成本O(log n)
    // int GetNumberOfK(vector<int> data, int k) {
    //     multiset<int> msData(data.begin(), data.end());
    //     return msData.count(k);
    // }

    // //利用STL库函数lower_bound()和upperBound(),O(log n)
    // int GetNumberOfK(vector<int> data ,int k) {
    //     auto iter1 = lower_bound(data.begin(), data.end(), k);
    //     auto iter2 = upper_bound(data.begin(), data.end(), k);
    //     return static_cast<int>(iter2 - iter1);
    // }
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
