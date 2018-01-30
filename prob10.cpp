
#include <iostream>
#include <string>
#include <cstring>

using std::string;


class Solution {
public:
    bool isMatch(string s, string p) {

        if (p.empty()) return s.empty(); 

        bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
        if (p.length() >= 2 && p[1] == '*') {
            return (isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
        } else {
            return (first_match && isMatch(s.substr(1), p.substr(1)));
        }
    }
    
    bool isMatch2(const char *s, const char *p) {

        if (*p=='\0') {
            return *s == '\0';
        }
        //p's length 1 is special case 
        if (*(p+1) == '\0' || *(p+1) !='*' ) {
            if (*s=='\0' || ( *p !='.' && *s != *p )) {
                return false;
            }
            return isMatch(s+1, p+1);
        }
        int len = strlen(s);
        int i = -1;
        while (i < len && (i <0 || *p=='.' || *p==*(s+i)) ){
            if (isMatch(s+i+1, p+2)) {
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
    std::cout << "isMatch(\"aa\",\"a\"):   false <------> " << boolToString(s.isMatch("aa","a")) << "\n";
    std::cout << "isMatch(\"aa\",\"aa\"):  true  <------> " << boolToString(s.isMatch("aa","aa")) << "\n";
    std::cout << "isMatch(\"aaa\",\"aa\"): false <------> " << boolToString(s.isMatch("aaa","aa")) << "\n";
    std::cout << "isMatch(\"aa\",\"a*\"):  true  <------> " << boolToString(s.isMatch("aa","a*")) << "\n";
    std::cout << "isMatch(\"aa\",\".*\"):  true  <------> " << boolToString(s.isMatch("aa",".*")) << "\n";
    std::cout << "isMatch(\"ab\",\".*\"):  true  <------> " << boolToString(s.isMatch("ab",".*")) << "\n";
    std::cout << "isMatch(\"aab\",\"cc*a*b\"): true <------> " << boolToString(s.isMatch("aab","c*a*b")) << "\n";
    std::cout << "method 2: \n";
    std::cout << "isMatch(\"aa\",\"a\"):   false <------> " << boolToString(s.isMatch2("aa","a")) << "\n";
    std::cout << "isMatch(\"aa\",\"aa\"):  true  <------> " << boolToString(s.isMatch2("aa","aa")) << "\n";
    std::cout << "isMatch(\"aaa\",\"aa\"): false <------> " << boolToString(s.isMatch2("aaa","aa")) << "\n";
    std::cout << "isMatch(\"aa\",\"a*\"):  true  <------> " << boolToString(s.isMatch2("aa","a*")) << "\n";
    std::cout << "isMatch(\"aa\",\".*\"):  true  <------> " << boolToString(s.isMatch2("aa",".*")) << "\n";
    std::cout << "isMatch(\"ab\",\".*\"):  true  <------> " << boolToString(s.isMatch2("ab",".*")) << "\n";
    std::cout << "isMatch(\"aab\",\"cc*a*b\"): true <------> " << boolToString(s.isMatch2("aab","c*a*b")) << "\n";
    return 0;
}