

#include <iostream>
#include <algorithm>
#include <stack>
#include <stack>
#include <string>

using namespace std;

/*
* Name: 栈的压入、弹出序列
* Description: 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
* 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
* 但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool result = false;

        if (!pushV.empty() && !popV.empty())
        {
            size_t pushVIndex = 0;
            size_t popVIndex = 0;
            stack<int> pushStack;
            
            while (popVIndex < popV.size())
            {
                while (pushStack.empty() || pushStack.top() != popV[popVIndex])
                {
                    if (pushVIndex >= pushV.size()) break;
                    pushStack.push(pushV[pushVIndex]);
                    ++pushVIndex;
                }

                if (pushStack.top() != popV[popVIndex])
                    break;
                pushStack.pop();
                ++popVIndex;
            }

            if (pushStack.empty() && popVIndex >= popV.size())
                result = true;
        }

        return result;
    }

    bool IsPopOrder1(vector<int> pushV,vector<int> popV) {
        if (pushV.empty() && popV.empty()) return true;
        if (pushV.empty() && !popV.empty()) return false;
        if (!pushV.empty() && popV.empty()) return false;

        stack<int> pushStack;
        size_t pushVIndex = 0;
        size_t popVIndex = 0;
        while (popVIndex < popV.size())
        {
            if (pushV[pushVIndex] == popV[popVIndex])
            {
                ++pushVIndex;
                ++popVIndex;
                if (pushVIndex >= pushV.size()) break;
            }
            else  
            {
                if (pushStack.empty() || pushStack.top() != popV[popVIndex])
                {
                    while (pushVIndex < pushV.size())
                    {
                        if (pushV[pushVIndex] != popV[popVIndex])
                        {
                            pushStack.push(pushV[pushVIndex++]);
                        }
                        else  
                        {
                            ++pushVIndex;
                            ++popVIndex;
                            continue;
                        }
                    }
                    break;
                }
                else  
                {
                    pushStack.pop();
                    ++popVIndex;
                }
            }
        }

        if (pushStack.empty() && popVIndex >= popV.size())
        {
            return true;
        }
        else 
        {
            for (; popVIndex < popV.size(); ++popVIndex)
            {
                if (pushStack.empty()) return false;
                if (pushStack.top() != popV[popVIndex])
                    return false;
                pushStack.pop();
            }
        }
        return true;
    }

};

std::string boolToString(bool input) 
{
    return input ? "True" : "False";
}
int main() 
{
    Solution s;
    vector<int> push1 = {1,2,3,4,5};
    vector<int> pop1 = {4,5,3,2,1};
    vector<int> pop2 = {1,3,5,4,2};
    vector<int> pop3 = {4,3,5,1,2};
    std::cout << "true --> " << boolToString(s.IsPopOrder(push1, pop1)) << "\n";
    std::cout << "true --> " << boolToString(s.IsPopOrder(push1, pop2)) << "\n";
    std::cout << "false --> " << boolToString(s.IsPopOrder(push1, pop3)) << "\n";
    std::cout << std::endl;
    return 0;
}
