
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

/*
* Name: 14. Longest Common Prefix
* Description: 
* Write a function to find the longest common prefix string amongst an array of strings.
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];     
        for (const auto &v : strs) {
            if (v.empty())
                return "";
        }
        size_t _left = 0;
        size_t _right = strs[0].size() - 1;
        if (_left == _right) {
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i] != strs[0]) {
                    return "";
                } 
            }
            return strs[0];
        }
        while (_left < _right && _left != _right - 1) {
            
            bool _ispass = true;
            size_t _mid = (_left + _right) / 2;
           // std::cout << "_left: " << _left << " _mid: " << _mid << " _right: " << _right << '\n';
            string _longest_str  = strs[0].substr(0, _mid);
            //std::cout << "_longest_str: " << _longest_str << '\n';

            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i].compare(0, _mid, _longest_str) != 0) {
                    _right = _mid;
                    _ispass = false;
                    break;
                }
            }
            if (_ispass) {
                _left = _mid;
            }
        }
        //std::cout << "_left: " << _left << " _right: " << _right << '\n';
        return strs[0].substr(0, _left);
    }
};

int main() 
{
    Solution s;
    // std::vector<std::string> strvec1 = {"lambda,bling", "lambda", "", "lambda,hello", "lambda,world"};
    // std::vector<std::string> strvec2 = {"lambda,bling", "lambda", "l", "lambda,hello", "lambda,world"};
    // std::vector<std::string> strvec3 = {"lambda,bling", "lambda", "lam", "lambda,hello", "lambda,world"};
    // std::vector<std::string> strvec4 = {"lambda,bling", "lambda", "lambda,", "lambda,hello", "lambda,world"};
    // std::vector<std::string> strvec5 = {};
    // std::vector<std::string> strvec6 = {"a"};
    std::vector<std::string> strvec7 = {"ab", "c"};
    std::vector<std::string> strvec8 = {"a", "b"};
    std::vector<std::string> strvec9 = {"c", "c"};
    std::vector<std::string> strvec10 = {"aa", "aa"};
    std::cout << "method 1: \n";    
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix(strvec1) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: l <------> " << s.longestCommonPrefix(strvec2) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: lam <------> " << s.longestCommonPrefix(strvec3) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: lambda <------> " << s.longestCommonPrefix(strvec4) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix(strvec5) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: a <------> " << s.longestCommonPrefix(strvec6) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix(strvec7) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix(strvec8) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect: c <------> " << s.longestCommonPrefix(strvec9) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect: aa <------> " << s.longestCommonPrefix(strvec10) << "\n";

    std::cout << std::endl;
    return 0;
}