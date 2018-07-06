
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 和为S的连续正数序列
* Description: 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
* 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
* 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
* 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
* 输出描述:
* 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*
*/
class Solution {
public:
    // 双指针(滑动窗口)思想
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        if (sum < 3) return result;

        int leftNum = 1; 
        int rightNum = 2;
        while (leftNum < rightNum)
        {
            // 等差数列求和
            int windowSum = (leftNum + rightNum) * (rightNum - leftNum + 1) / 2;
            if (windowSum < sum)
            {
                ++rightNum;
            }
            else if (windowSum > sum)
            {
                ++leftNum;
            }
            else  
            {
                vector<int> oneSet;
                for (int i = leftNum; i <= rightNum; ++i)
                {
                    oneSet.push_back(i);
                }
                result.push_back(oneSet); 
                //result.insert(result.begin(), oneSet);
                ++rightNum;   
            }
        }
        return result;
    }
    vector<vector<int> > FindContinuousSequence_1(int sum) {
        vector<vector<int> > result;
        if (sum < 3) return result;
        for (int setSize = 2; ; ++setSize)
        {
            // 等差数列的求和公式：S = (1 + n) * n / 2
            int diffSum = (0 + setSize-1) * setSize / 2;
            int remain = (sum - diffSum) % setSize;
            int base = (sum - diffSum) / setSize;
            if (remain == 0 && base != 0)
            {
                vector<int> oneSet;
                for (int i = 0; i < setSize; ++i)
                {
                    oneSet.push_back(base+i);
                }
                //result.push_back(oneSet); 
                result.insert(result.begin(), oneSet);                 
            }
            if (base < 1)   break;
        }
        //std::reverse(result.begin(), result.end());
        return result;
    }
};
void printVector(vector<vector<int>>& vec)
{
    for (auto& v1 : vec)
    {
        for (auto v2 : v1)
            std::cout << v2 << " ";
        std::cout << "\n";
    }
}
int main() 
{
    Solution s;

    std::cout << "please input a number:";
    vector<vector<int> > result;
    int n = 0;
    while (std::cin >> n)
    {
        if (n == 1) break;
        result = s.FindContinuousSequence(n);
        printVector(result);
        std::cout << "\n please input a number:";
    }    
    std::cout << std::endl;
    return 0;
}
