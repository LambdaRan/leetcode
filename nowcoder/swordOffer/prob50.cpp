
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
* Name: 数组中重复的数字
* Description: 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
* 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
* 请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
* 那么对应的输出是第一个重复的数字2。
*
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false

    // 方法一：使用set
    // 方法二：先排序
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length <= 1) return false;

        std::unordered_set<int> onlyValueSet({numbers[0]});
        for (int i = 1; i < length; ++i)
        {
            if (onlyValueSet.find(numbers[i]) != onlyValueSet.end())
            {
                *duplication = numbers[i];
                return true;
            }
            else  
            {
                onlyValueSet.insert(numbers[i]);
            }
        }
        return false;
    }
};

std::string boolToString(bool input) 
{
    return input ? "True" : "False";
}
int main() 
{
    Solution s;
    std::vector<int> vec1 = {2,1,3,1,4};
    int result = 0;
    std::cout << "find: " << boolToString(s.duplicate(vec1.data(), static_cast<int>(vec1.size()), &result)) << "\n";
    std::cout << "deplicate value: " << result << "\n";
    std::cout << std::endl;
    return 0;
}
