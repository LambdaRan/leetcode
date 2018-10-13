
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <queue>

using namespace std;
/*
* Name: 219. Contains Duplicate II
* Website: https://leetcode.com/problems/contains-duplicate-ii/description/
* Description: 
*
*/
class MyStack
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    /** Initialize your data structure here. */
    MyStack() : qOne_(), qTwo_() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        if (!qOne_.empty())
            qOne_.push(x);
        else 
            qTwo_.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (qOne_.empty())
        {
            while (qTwo_.size() > 1)
            {
                qOne_.push(qTwo_.front());
                qTwo_.pop();
            }
            int result = qTwo_.front();
            qTwo_.pop();
            return result;
        }
        else 
        {
            while (qOne_.size() > 1)
            {
                qTwo_.push(qOne_.front());
                qOne_.pop();
            }
            int result = qOne_.front();
            qOne_.pop();
            return result;
        }
    }
    
    /** Get the top element. */
    int top() {
        if (qOne_.empty())
        {
            return qTwo_.back();
            // while (qTwo_.size() > 1)
            // {
            //     qOne_.push(qTwo_.front());
            //     qTwo_.pop();
            // }
            // int result = qTwo_.front();
            // qTwo_.pop();
            // qOne_.push(result);
            // return result;
        }
        else 
        {
            return qOne_.back();
            // while (qOne_.size() > 1)
            // {
            //     qTwo_.push(qOne_.front());
            //     qOne_.pop();
            // }
            // int result = qOne_.front();
            // qOne_.pop();
            // qTwo_.push(result);
            // return result;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return qOne_.empty() && qTwo_.empty();
    }
private:
    std::queue<int> qOne_;
    std::queue<int> qTwo_;
};

int main()
{
    //Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}