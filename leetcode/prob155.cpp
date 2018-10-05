
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <stack>

using namespace std;
/*
* Name: 155. Min Stack
* WebSite: https://leetcode.com/problems/min-stack/description/
* Description: 
*
*/
class MinStack {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    // 使用两个栈来完成：
    // sk1存放原有数据
    // sk2 存放当前最小元素
    MinStack() 
        : skOrigin_(), skMinVal_() 
    {}
    
    void push(int x) {
        skOrigin_.push(x);
        if (skMinVal_.empty() || x < skMinVal_.top())
            skMinVal_.push(x);
        else  
        {
            int top = skMinVal_.top();
            skMinVal_.push(top);
        }
    }
    
    void pop() {
        skOrigin_.pop();
        skMinVal_.pop();
    }
    
    int top() {
        return skOrigin_.top();
    }
    
    int getMin() {
        return skMinVal_.top();
    }
private: 
    stack<int> skOrigin_;
    stack<int> skMinVal_;

public: 
    // 方法二： 使用一个栈来保存当前入栈元素与最小元素的差值
    // MinStack() 
    //     : skValueDiff_(), minValue_(std::numeric_limits<int>::min()) 
    // {}
//     void push(int v) {
//         if (skValueDiff_.empty())
//         {
//             skValueDiff_.push(0);
//             minValue_ = x;
//         }
//         else  
//         {
//             skValueDiff_.push(x-minValue_);
//             if (x < minValue_) minValue_ = x;
//         }
//     }

//     void pop()
//     {
//         if (!skValueDiff_.empty())
//         {
//             int val = skValueDiff_.top();
//             skValueDiff_.pop();
//             if (val < 0)    
//                 minValue_ -= val;
//         }
//     }

//     int top() const 
//     {
//         if (skValueDiff_.empty())
//             return std::numeric_limits<int>::min();
//         int val = skValueDiff_.top();
//         return (val < 0 ? minValue_ : minValue_ + val);
//     }
    
//     int getMin() const 
//     {
//         return minValue_;
//     }
// private: 
//     int minValue_;
//     stack<int> skValueDiff_;
};

int main() 
{
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin();  // --> Returns -3.
    minStack->pop();
    minStack->top();      //--> Returns 0.
    minStack->getMin();   //--> Returns -2.
    return 0;
}