
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
    * Runtime:  8  ms
    * Your runtime beats  24.06% of cpp submissions. 
    */
    string longestCommonPrefix(vector<string>& strs);
    /*
    * Runtime:  9  ms
    * Your runtime beats  5.68% of cpp submissions.
    * Approach #1 (Horizontal scanning) 
    */
    string longestCommonPrefix1(vector<string>& strs);
    /*
    * Runtime:  8  ms
    * Your runtime beats  24.06% of cpp submissions.
    * Approach #2 (Vertical scanning)
    */
    string longestCommonPrefix2(vector<string>& strs);
    /*
    * Runtime:  8  ms
    * Your runtime beats  24.06% of cpp submissions.
    * Approach #3 (Divide and conquer) // 分而治之
    */
    string longestCommonPrefix3(vector<string>& strs);

    /*
    * Runtime:  8  ms
    * Your runtime beats  24.06% of cpp submissions.
    * Approach #4 (Binary search)
    */
    string longestCommonPrefix4(vector<string>& strs);
private:
    string commonPrefix(string &left, string &right);
    string longestCommonPrefix(vector<string>&, int l, int r);
};
string Solution::longestCommonPrefix(vector<string>& strs)
{
    size_t fsize = strs.size();
    if (fsize == 0) return "";

    std::string flongest;
    for (size_t i = 0; i < strs[0].size(); ++i) {
        std::string ftmp = strs[0].substr(0, i+1);
        bool fispass = true;
        for (size_t j = 1; j < fsize; ++j) {
            if (strs[j].compare(0, i+1, ftmp) != 0) {
                fispass = false;
                break;
            }
        }
        if (!fispass) {
            break;
        }
        flongest = ftmp;
    }
    return flongest;
}
string Solution::longestCommonPrefix1(vector<string>& strs) 
{
    size_t vsize = strs.size();
    if (vsize == 0) return "";

    std::string longest_prefix = strs[0];
    for (size_t i = 1; i < vsize; ++i) {
        for (size_t j = 1; j <= longest_prefix.size(); ++j) {
            if (strs[i].compare(0, j, longest_prefix, 0, j) != 0) {
                longest_prefix = strs[i].substr(0, j-1);
                break;
            }
        }
        if (longest_prefix.empty())
            break;
    }
    return longest_prefix;
}
string Solution::longestCommonPrefix2(vector<string>& strs) 
{
    size_t vsize = strs.size();
    if (vsize == 0) return "";

    std::string longest_prefix = strs[0];
    for (size_t i = 0; i < strs[0].length(); ++i) {
        for (size_t j = 1; j < vsize; ++j) {
            if (strs[0][i] != strs[j][i] || i == strs[j].length()) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}
string Solution::longestCommonPrefix3(vector<string>& strs) 
{
    if (strs.empty()) return "";    
    return longestCommonPrefix(strs, 0 , static_cast<int>(strs.size() - 1));
}

string Solution::longestCommonPrefix(vector<string>& strs, int l, int r) 
{
    if (l == r) {
        return strs[l];
    } else {
        int mid = (l + r) / 2;
        string lcpLeft =   longestCommonPrefix(strs, l , mid);
        string lcpRight =  longestCommonPrefix(strs, mid + 1, r);
        return commonPrefix(lcpLeft, lcpRight);
   }
}
string Solution::commonPrefix(string &left, string &right) 
{
    auto min = std::min(left.length(), right.length());       
    for (int i = 0; i < min; ++i) {
        if (left.at(i) != right.at(i))
            return left.substr(0, i);
    }
    return left.substr(0, min);
}
string Solution::longestCommonPrefix4(vector<string>& strs) 
{
    
    size_t vsize = strs.size();
    if (vsize <= 0) return "";
    if (vsize == 1) return strs[0];     
    
    int left = 1;
    int right = static_cast<int>(strs[0].size());

    string longest_prefix;
    while (left <= right) {
        
        bool ispass = true;
        int mid = (left + right) / 2;
        //std::cout << "_left: " << _left << " _mid: " << _mid << " _right: " << _right << '\n';
            string tmp = strs[0].substr(0, mid);
        //std::cout << "_longest_str: " << _longest_str << '\n';

        for (size_t i = 1; i < vsize; ++i) {
            if (strs[i].compare(0, mid, tmp) != 0) {
                right = mid - 1;
                ispass = false;
                break;
            }
        }
        if (ispass) {
            left = mid + 1;
            longest_prefix = tmp;
        }
    }
    //std::cout << "_left: " << _left << " _right: " << _right << '\n';
    return longest_prefix;        
}
int main() 
{
    Solution s;
    std::vector<std::string> strvec1 = {"lambda,bling", "lambda", "", "lambda,hello", "lambda,world"};
    std::vector<std::string> strvec2 = {"lambda,bling", "lambda", "l", "lambda,hello", "lambda,world"};
    std::vector<std::string> strvec3 = {"lambda,bling", "lambda", "lam", "lambda,hello", "lambda,world"};
    std::vector<std::string> strvec4 = {"lambda,bling", "lambda", "lambda,", "lambda,hello", "lambda,world"};
    std::vector<std::string> strvec5 = {};
    std::vector<std::string> strvec6 = {"a"};
    std::vector<std::string> strvec7 = {"ab", "c"};
    std::vector<std::string> strvec8 = {"a", "b"};
    std::vector<std::string> strvec9 = {"c", "c"};
    std::vector<std::string> strvec10 = {"aa", "aa"};
    std::vector<std::string> strvec11 = {"aa", "ab"};
    // std::cout << "method 1: \n";    
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix(strvec1) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: l <------> " << s.longestCommonPrefix(strvec2) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: lam <------> " << s.longestCommonPrefix(strvec3) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: lambda <------> " << s.longestCommonPrefix(strvec4) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix(strvec5) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: a <------> " << s.longestCommonPrefix(strvec6) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix(strvec7) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix(strvec8) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: c <------> " << s.longestCommonPrefix(strvec9) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: aa <------> " << s.longestCommonPrefix(strvec10) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: a <------> " << s.longestCommonPrefix(strvec11) << "\n";
    // std::cout << "method 2: \n";    
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix2(strvec1) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: l <------> " << s.longestCommonPrefix2(strvec2) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: lam <------> " << s.longestCommonPrefix2(strvec3) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: lambda <------> " << s.longestCommonPrefix2(strvec4) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix2(strvec5) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: a <------> " << s.longestCommonPrefix2(strvec6) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix2(strvec7) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix2(strvec8) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: c <------> " << s.longestCommonPrefix2(strvec9) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: aa <------> " << s.longestCommonPrefix2(strvec10) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: a <------> " << s.longestCommonPrefix2(strvec11) << "\n";
    std::cout << "method 3: \n";    
    std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix3(strvec1) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect: l <------> " << s.longestCommonPrefix3(strvec2) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect: lam <------> " << s.longestCommonPrefix3(strvec3) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect: lambda <------> " << s.longestCommonPrefix3(strvec4) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix3(strvec5) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect: a <------> " << s.longestCommonPrefix3(strvec6) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix3(strvec7) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix3(strvec8) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect: c <------> " << s.longestCommonPrefix3(strvec9) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect: aa <------> " << s.longestCommonPrefix3(strvec10) << "\n";
    std::cout <<  "longestCommonPrefix(vector<string>&): expect: a <------> " << s.longestCommonPrefix3(strvec11) << "\n";
    // std::cout << "method 4: \n";    
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix4(strvec1) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: l <------> " << s.longestCommonPrefix4(strvec2) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: lam <------> " << s.longestCommonPrefix4(strvec3) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: lambda <------> " << s.longestCommonPrefix4(strvec4) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix4(strvec5) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: a <------> " << s.longestCommonPrefix4(strvec6) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix4(strvec7) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect:  <------> " << s.longestCommonPrefix4(strvec8) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: c <------> " << s.longestCommonPrefix4(strvec9) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: aa <------> " << s.longestCommonPrefix4(strvec10) << "\n";
    // std::cout <<  "longestCommonPrefix(vector<string>&): expect: a <------> " << s.longestCommonPrefix4(strvec11) << "\n";

    std::cout << std::endl;
    return 0;
}