

// https://leetcode.com/problems/implement-strstr/description/
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
* Name: 28. Implement strStr()
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
<<<<<<< HEAD
    string countAndSay(int n) 
    {
        string result;
        if (n == 0) return result;
        result = "1";
        for (int k = 2; k <= n; ++k)
        {
            string cur = "";
            size_t first = 0;
            size_t second = 1;
            while (second < result.size())
            {
                if (result[second] != result[first])
                {
                    int cnt = second - first;
                    cur += cnt + '0';
                    cur += result[first];
                    first = second;
                }
                ++second;
            }
            if (first < second)
            {
                int cnt = second - first;
                cur += cnt + '0';
                cur += result[first];
            }
            result = cur;
        }
        return result;
=======

    int strStr(string haystack, string needle) {
        // return haystack.find(needle);
        return index_kmp(haystack, needle, 0);
    }
std::vector<int> get_next(const std::string &str)
{
    assert(str.size() > 0);

    std::vector<int> next(str.size());
    next[0] = -1;
    size_t i = 0;
    int j = -1;
    while (i < str.size() - 1)
    {
        if (j == -1 || str[i] == str[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else  
        {
            j = next[j];
        }
    }
    return next;
}

std::vector<int> get_nextval(const std::string &str)
{
    assert(str.size() > 0);

    std::vector<int> next(str.size());
    next[0] = -1;
    size_t i = 0;
    int j = -1;
    while (i < str.size() - 1)
    {
        if (j == -1 || str[i] == str[j])
        {
            ++i;
            ++j;
            //next[i] = j;

            if (str[i] != str[j])
                next[i] = j;
            else  
                next[i] = next[j];
        }
        else  
        {
            j = next[j];
        }
    }
    return next;
}
int index_kmp(const std::string &mstr, const std::string &tstr, int position)
{
    int size_mstr = static_cast<int>(mstr.size());
    int size_tstr = static_cast<int>(tstr.size());
    
    if (size_tstr == 0) return 0;
    if (size_mstr == 0 || size_tstr > size_mstr) return -1;
    // if (size_mstr == 0 || size_tstr == 0 || position > size_mstr)
    //     return -1;

    std::vector<int> next = get_nextval(tstr);
    int j = 0;
    int i = position;
    while (i < size_mstr && j < size_tstr)
    {
        if (j == -1 || mstr[i] == tstr[j])
        {
            ++i;
            ++j;
        }
        else  
        {
            j = next[j];
        }
>>>>>>> 9cbf19112ca2e52fd44a150bd6864e515ee09346
    }

    if (j >= size_tstr)
        return i - size_tstr;
    else  
        return -1;
}
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}