
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <stack>

using namespace std;
/*
* Name: 232. Implement Queue using Stacks
* Website: https://leetcode.com/problems/implement-queue-using-stacks/description/
* Description: 
*
*/
class MyQueue
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    /** Initialize your data structure here. */
    MyQueue() :insk(), outsk() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        insk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (outsk.empty())
        {
            while (!insk.empty())
            {
                outsk.push(insk.top());
                insk.pop();
            }
        }
        //if (!outsk.empty())
        int result = outsk.top();
        outsk.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        if (outsk.empty())
        {
            while (!insk.empty())
            {
                outsk.push(insk.top());
                insk.pop();
            }
        }
        return outsk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return insk.empty() && outsk.empty();
    }
private: 
    std::stack<int> insk;
    std::stack<int> outsk;
};

int main()
{
    //Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}