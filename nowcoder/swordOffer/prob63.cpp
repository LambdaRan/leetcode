
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>


using namespace std;

/*
* Name: 数据流中的中位数
* Description: 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
* 那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
* 那么中位数就是所有数值排序之后中间两个数的平均值。
*
*/
class Solution {
public:
    // 利用两个优先级队列，一个递增一个递减 
    void Insert(int num)
    {
        // 大顶堆中存储小值，也就是排序后的前半部分
        if(lessQueue_.empty() || num <= lessQueue_.top()) 
            lessQueue_.push(num);
        else 
            greaterQueue_.push(num);
        
        if(lessQueue_.size() == greaterQueue_.size() + 2)
        {
            greaterQueue_.push(lessQueue_.top());
            lessQueue_.pop();
        }   
        if(lessQueue_.size() + 1 == greaterQueue_.size())
        {
            lessQueue_.push(greaterQueue_.top());
            greaterQueue_.pop(); 
        }       
    }

    double GetMedian()
    { 
        return lessQueue_.size() == greaterQueue_.size() ? 
                (lessQueue_.top() + greaterQueue_.top()) / 2.0 : 
                static_cast<double>(lessQueue_.top());
    }
private: 
    // 大顶堆 中所有的元素值都小于小顶堆中的元素值
    std::priority_queue<int, std::vector<int>, std::less<int>> lessQueue_;
    // 小顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> greaterQueue_;
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
