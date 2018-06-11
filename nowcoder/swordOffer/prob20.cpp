
#include <iostream>
#include <stack>


using namespace std;

/*
* Name: 包含min函数的栈
* Description: 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*
*/
class Solution {
public:
    Solution()
        : dataStack_(), minStack_()
    {}

    void push(int value) {
        dataStack_.push(value);
        if (minStack_.empty() || value < minStack_.top())
            minStack_.push(value);
        else 
            minStack_.push(minStack_.top());
    }
    void pop() {
        dataStack_.pop();
        minStack_.pop();
    }
    int top() {
        return dataStack_.top();
    }
    int min() {
        return minStack_.top();
    }
private:
    stack<int> dataStack_;
    stack<int> minStack_;
};
int main() 
{
    Solution s;
    s.push(3);
    s.push(4);
    s.push(2);
    s.push(1);
    std::cout << "min value: 1 --> " << s.min() << "\n";
    s.pop();
    std::cout << "min value: 2 --> " << s.min() << "\n"; 
    s.pop();
    s.push(0);   
    std::cout << "min value: 0 --> " << s.min() << "\n";     

    std::cout << std::endl;
    return 0;
}