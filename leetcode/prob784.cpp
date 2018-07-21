
#include <iostream>
#include <string>
#include <vector>

#include <ctype.h>

using namespace std;

/*
* Name: 784. Letter Case Permutation
* Description: 
* Given a string S, we can transform every letter individually to be lowercase or uppercase 
* to create another string.  Return a list of all possible strings we could create.
* 
* Examples:
* Input: S = "a1b2"
* Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
* 
* Input: S = "3z4"
* Output: ["3z4", "3Z4"]
* 
* Input: S = "12345"
* Output: ["12345"]
* Note:
* 
* S will be a string with length at most 12.
* S will consist only of letters or digits.
*
*/
class Solution {
public:
    /*
    * Runtime:  4  ms
    * Your runtime beats 100.00 % of cpp submissions.
    */
    vector<string> letterCasePermutation(string S) {
        vector<string> result;    
        if ( (S.size() == 0) || (S.size() == 1 && !isalpha(S[0])) ){
            result.push_back(S);
            return result;
        }
        _letterCasePermutation_dfs(result, S, 0);
        return result;
    }
private: 
    void _letterCasePermutation_dfs(std::vector<std::string>& result, 
                                    std::string& str, 
                                    int index)
    {
        if (index == str.size()-1) // 到达尾端保存结果
        {
            if (isalpha(str[index]))
            {
                str[index] = static_cast<char>(tolower(static_cast<unsigned char>(str[index])));
                result.push_back(str);
                str[index] = static_cast<char>(toupper(static_cast<unsigned char>(str[index])));
                result.push_back(str);
            }
            else  
            {
                result.push_back(str);
            }
        }
        else  
        {
            if (::isalpha(str[index])) // 是字母，改变当前字母大小写
            {
                str[index] = static_cast<char>(tolower(static_cast<unsigned char>(str[index])));
                _letterCasePermutation_dfs(result, str, index+1);
                str[index] = static_cast<char>(toupper(static_cast<unsigned char>(str[index])));
                _letterCasePermutation_dfs(result, str, index+1);
            }
            else // 是数字直接跳到下一个字符
            {
                _letterCasePermutation_dfs(result, str, index+1);
            }
        }
    }
};
void printResult(const std::vector<string>& strvector)
{
    std::cout << "[\n";
    for (auto& v : strvector)
        std::cout << v << "\n";
    std::cout << "]" << std::endl;
}
int main() 
{
    Solution s;
    std::vector<std::string> res;
    std::cout << "method 1: \n";
    res = s.letterCasePermutation("a1b2");
    printResult(res);

    res = s.letterCasePermutation("3z4");
    printResult(res);

    res = s.letterCasePermutation("12345");
    printResult(res);

    std::cout << std::endl;
    return 0;
}