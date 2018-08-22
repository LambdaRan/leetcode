

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int longestValidParentheses(string s) 
{
    int maxLen = 0;
    int lastError = -1;
    vector<int> stack;
    for(int i=0; i< static_cast<int>(s.size()); i++)
    {
        if (s[i] == '(')
        {
            stack.push_back(i);
        }
        else if (s[i] == ')') 
        {
            if (stack.size() > 0)
            {
                stack.pop_back();
                int len;
                if (stack.size() == 0)
                {
                    len = i - lastError;
                } 
                else 
                {
                    len = i - stack.back();
                }

                if (len > maxLen) 
                {
                    maxLen = len;
                }
            }
            else
            {
                lastError = i;
            }
        }
        else 
        {
            stack.clear();
            lastError = i;
        }
    }
    return maxLen;
}

int main()
{

    string line;
    while (getline(cin, line))
    {
        cout << longestValidParentheses(line) << endl;
    }
    return 0;
}