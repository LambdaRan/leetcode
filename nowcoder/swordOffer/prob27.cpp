

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

/*
* Name: 字符串的排列
* Description: 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
* 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
* 输入描述:
*   输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/
class Solution {
public:
    vector<string> Permutation(string str) 
    {
        if (str.empty()) return vector<string>();

        set<string> result;
        sort(str.begin(), str.end());
        _permutation(str, 0, str.size(), result);
        return vector<string>(result.begin(), result.end());
    }
private: 
    void _permutation(string& str, size_t left, size_t right, set<string>& result)
    {
        if (left == right)
        {
            result.insert(str);
        }
        else  
        {
            for (size_t index = left; index < right; ++index)
            {
                if (left != index)
                    swap(str[left], str[index]);
                
                _permutation(str, left+1, right, result);

                if (left != index)
                    swap(str[left], str[index]);    
            }
        }
    }
public:
    vector<string> Permutation_Algorithm(string str) {
        
        if (str.empty()) return vector<string>();
        vector<string> result;
        do {
            result.push_back(str);
        } while (next_permutation(str.begin(), str.end()));
        return result;
    }

};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    vector<string> res = s.Permutation("abc");
    for (auto &v : res)
        std::cout << v << "\n";
    std::cout << std::endl;
    return 0;
}
