
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

/*
* Name: 连续子数组的最大和
* Description: HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
* 今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
* 当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,
* 并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,
* 到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)
*
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() == 1) return array[0];

        int maxSum = array.front();
        int curSum = array.front();

        for_each(std::next(array.begin()), array.end(), 
            [&maxSum, &curSum](const int value) -> void
            { 
                curSum = curSum<=0 ? value : curSum+value;
                maxSum = std::max({maxSum, value, curSum});
            });

        return maxSum;
    }
};

int main() 
{
    Solution s;
    vector<int> vec = {6,-3,-2,7,-15,1,2,2};
    std::cout << "max sum: 8 --> " << s.FindGreatestSumOfSubArray(vec) << "\n";

    vector<int> vec2 = {1,-2,3,10,-4,7,2,-5};
    std::cout << "max sum: 18 --> " << s.FindGreatestSumOfSubArray(vec2) << "\n";

    std::cout << std::endl;
    return 0;
}
