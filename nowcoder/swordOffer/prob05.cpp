
#include <iostream>

#include <vector>
#include <stack>

using namespace std;

/*
* Name: 用两个栈实现队列
* Description: 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*
*/
class Solution
{
public:
    Solution()
        : stack1(), stack2()
    {}

    void push(int node) {
        stack1.push(node);
    }
    int pop() {
        
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }
    // int pop() {
        
    //     while (!stack1.empty())
    //     {
    //         stack2.push(stack1.top());
    //         stack1.pop();
    //     }
    //     int ret = stack2.top();
    //     stack2.pop();
    //     while (!stack2.empty())
    //     {
    //         stack1.push(stack2.top());
    //         stack2.pop();
    //     }
    //     return ret;
    // }

private:
    stack<int> stack1;
    stack<int> stack2;
};
int main() 
{
    vector<int> v1 = {1,2,3,4,5,6,7,8,9};
    Solution s;

    std::cout << "method 1: \n";
    for (size_t i = 0; i < v1.size(); ++i)
        s.push(v1[i]);

    for (size_t i = 0; i < v1.size(); ++i)
        cout << s.pop() << " ";    
    std::cout << std::endl;

    return 0;
}