
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

/*
* Name: 正则表达式匹配
* Description: 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
* 而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
* 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/
class Solution {
public:
    bool match(char* s, char* p)
    {
        if (*p=='\0') {
            return *s == '\0';
        }
        //p's length 1 is special case 
        if (*(p+1) == '\0' || *(p+1) !='*' ) {
            if (*s=='\0' || ( *s != *p && *p !='.' )) {
                return false;
            }
            return match(s+1, p+1);
        }
        int len = static_cast<int>(strlen(s));
        int i = -1;
        while (i < len && (i < 0 || *p=='.' || *p==*(s+i)) ){
            if (match(s+i+1, p+2)) {
                return true;
            }
            i++;
        } 
        return false; 
    }
};
std::string boolToString(bool input) {
    return input ? "true" : "false";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout << "isMatch(\"aa\",\"a\"):   false <------> " << boolToString(s.match("aa","a")) << "\n";
    std::cout << "isMatch(\"aa\",\"aa\"):  true  <------> " << boolToString(s.match("aa","aa")) << "\n";
    std::cout << "isMatch(\"aaa\",\"aa\"): false <------> " << boolToString(s.match("aaa","aa")) << "\n";
    std::cout << "isMatch(\"aa\",\"a*\"):  true  <------> " << boolToString(s.match("aa","a*")) << "\n";
    std::cout << "isMatch(\"aa\",\".*\"):  true  <------> " << boolToString(s.match("aa",".*")) << "\n";
    std::cout << "isMatch(\"ab\",\".*\"):  true  <------> " << boolToString(s.match("ab",".*")) << "\n";
    std::cout << "isMatch(\"aab\",\"cc*a*b\"): true <------> " << boolToString(s.match("aab","c*a*b")) << "\n";
    // std::cout << "method 2: \n";
    // std::cout << "isMatch(\"aa\",\"a\"):   false <------> " << boolToString(s.isMatch2("aa","a")) << "\n";
    // std::cout << "isMatch(\"aa\",\"aa\"):  true  <------> " << boolToString(s.isMatch2("aa","aa")) << "\n";
    // std::cout << "isMatch(\"aaa\",\"aa\"): false <------> " << boolToString(s.isMatch2("aaa","aa")) << "\n";
    // std::cout << "isMatch(\"aa\",\"a*\"):  true  <------> " << boolToString(s.isMatch2("aa","a*")) << "\n";
    // std::cout << "isMatch(\"aa\",\".*\"):  true  <------> " << boolToString(s.isMatch2("aa",".*")) << "\n";
    // std::cout << "isMatch(\"ab\",\".*\"):  true  <------> " << boolToString(s.isMatch2("ab",".*")) << "\n";
    // std::cout << "isMatch(\"aab\",\"cc*a*b\"): true <------> " << boolToString(s.isMatch2("aab","c*a*b")) << "\n";

    std::cout << std::endl;
    return 0;
}
