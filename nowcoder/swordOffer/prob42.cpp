
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

/*
* Name: 和为S的两个数字
* Description: 输入一个递增排序的数组和一个数字S，在数组中查找两个数，
* 使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
* 输出描述:
* 对应每个测试案例，输出两个数，小的先输出。
*
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        
        vector<int> result;
        if (array.size() < 2) return result;

        int leftIndex = 0;
        int rightIndex = static_cast<int>(array.size()-1);
        while (leftIndex < rightIndex)
        {
            int twoSum = array[leftIndex] + array[rightIndex];
            if (twoSum < sum)
            {
                ++leftIndex;
            }
            else if (twoSum > sum)
            {
                --rightIndex;
            } 
            else
            {
                // 最两头的乘积最小
                result.push_back(array[leftIndex]);
                result.push_back(array[rightIndex]);
                break;
            }
        }
        return result;
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
