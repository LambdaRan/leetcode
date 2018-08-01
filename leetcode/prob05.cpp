
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 5. Longest Palindromic Substring
* Description: Given a string s, find the longest palindromic substring in s. 
* You may assume that the maximum length of s is 1000.
* Example 1:
* Input: "babad"
* Output: "bab"
* Note: "aba" is also a valid answer.
* 
* Example 2:
* Input: "cbbd"
* Output: "bb"
*
*/
class Solution {
public:
    string longestPalindrome(string &s) {
    int n = s.size();
    if (n<=1) 
        return s;

    string longest;
    
    string str;
    for (int i=0; i<n-1; i++) {
        str = expandAroundCenter(s, i, i);
        if (str.size() > longest.size()){
            longest = str;
        } 
        str = expandAroundCenter(s, i, i+1);
        if (str.size() > longest.size()){
            longest = str;
        } 
    }

    return longest; 
    }
    string expandAroundCenter(string &s, int left, int right) {
        
        int n = s.length();
        int l = left;
        int r = right;
        while (l >=0 && r <= n && s[l] == s[r]) {
            
            --l;
            ++r;
        }
        return s.substr(l+1, r-l-1);
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}