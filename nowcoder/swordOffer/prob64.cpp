
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>

using namespace std;

/*
* Name: 滑动窗口的最大值
* Description: 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
* 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
* 他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
* {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
* {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。 
*
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if (size == 0 || size > num.size()) return vector<int>();
        std::set<int, std::greater<int>> maxElement(num.begin(), std::next(num.begin(), size-1));
        std::vector<int> result;
        for (size_t i = size-1; i < num.size(); ++i)
        {
            maxElement.insert(num[i]);
            result.push_back(*maxElement.begin());
            maxElement.erase(num[i+1-size]);
        }
        return result;
    }
    vector<int> maxInWindows_reference(const vector<int> &num, unsigned int size)
    {
        if (size == 0 || size > num.size()) return vector<int>();
        std::vector<int> res;
        std::deque<size_t> maxIndexs; // 存储下标
        for (size_t i = 0; i < num.size(); ++i)
        {
            //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
            while (maxIndexs.size() && num[maxIndexs.back()] <= num[i]) 
                maxIndexs.pop_back();
            //当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
            while (maxIndexs.size() && i - maxIndexs.front() + 1 > size) 
                maxIndexs.pop_front();
            //把每次滑动的num下标加入队列
            maxIndexs.push_back(i);
            //当滑动窗口首地址i大于等于size时才开始写入窗口最大值
            if (size && i + 1 >= size)
                res.push_back(num[maxIndexs.front()]);
        }
        return res;
    }
};

int main() 
{
    Solution s;
    std::vector<int> vec = {2,3,4,2,6,2,5,1};
    std::cout << "method 1: \n";
    std::vector<int> res = s.maxInWindows(vec, 3);
    
    for(int v : res)
    {
        std::cout << v << " ";
    }
    
    std::cout << std::endl;
    return 0;
}
