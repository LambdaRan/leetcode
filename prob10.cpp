
#include <iostream>
#include <string>

using std::string;


class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();


        if (s_size == 0 && s_size == p_size)
            return true;
        if ((s_size == 0 && p_size != 0) || (p_size == 0 && s_size != 0))
            return false;

        std::string::size_type dotfind = p.find('.');
        std::string::size_type starfind = p.find('*');
        if (dotfind == std::string::npos && starfind == std::string::npos) {// 不存在.或*
            //if (s_size != p_size)
            //    return false;
            //else 
                return (s == p);
        } else {//　存在.或*
            for (int i = 0, j = 0; i < s_size && j < p_size; ++i, ++j) {

                
            }
        }

    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout << "isMatch(\"aa\",\"a\"):   false <------> " << boolToString(s.isMatch("aa","a")) << "\n";
    std::cout << "isMatch(\"aa\",\"aa\"):  true  <------> " << boolToString(s.isMatch("aa","aa")) << "\n";
    std::cout << "isMatch(\"aaa\",\"aa\"): false <------> " << boolToString(s.isMatch("aaa","aa")) << "\n";
    std::cout << "isMatch(\"aa\",\"a*\"):  true  <------> " << boolToString(s.isMatch("aa","a*")) << "\n";
    std::cout << "isMatch(\"aa\",\".*\"):  true  <------> " << boolToString(s.isMatch("aa",".*")) << "\n";
    std::cout << "isMatch(\"ab\",\".*\"):  true  <------> " << boolToString(s.isMatch("ab",".*")) << "\n";
    std::cout << "isMatch(\"aab\",\"c*a*b\"): true <------> " << boolToString(s.isMatch("aab","c*a*b")) << "\n";
    return 0;
}