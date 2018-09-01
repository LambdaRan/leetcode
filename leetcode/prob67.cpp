

// https://leetcode.com/problems/add-binary/description/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 67. Add Binary
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    string addBinary(string a, string b) 
    {
        int as = static_cast<int>(a.size())-1;
        int bs = static_cast<int>(b.size())-1;
        string result = "";
        int remain = 0;
        for (;as >= 0 && bs >= 0; --as, --bs)
        {
            if (a[as] == '1' && b[bs] == '1')
            {
                result += remain ? "1" : "0";
                remain = 1;
            }
            else if(a[as] == '0' && b[bs] == '0')
            {
                
                result += remain ? "1" : "0";
                remain = 0;
            }
            else  
            {
                result += remain ? "0" : "1";
            }
        }

        for (; as >= 0; --as)
        {
            if (a[as] == '1')
                result += remain ? "0" : "1";
            else  
            {
                result += remain ? "1" : "0";
                if (remain) remain = 0;
            }
        }

        for (; bs >= 0; --bs)
        {
            if (b[bs] == '1')
                result += remain ? "0" : "1";
            else  
            {
                result += remain ? "1" : "0";
                if (remain) remain = 0;
            }
        }
        
        if (remain) result += "1";
        std::reverse(result.begin(), result.end());
        return result;
    }
};
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    string astr = "";
    string bstr = "";
    while (cin >> astr >> bstr)
    {
        string ret = s.addBinary(astr, bstr);
        cout << ret << endl;
    }
    std::cout << std::endl;
    return 0;
}
