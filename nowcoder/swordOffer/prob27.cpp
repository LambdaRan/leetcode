

#include <iostream>
#include <algorithm>
#include <vector>

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

        vector<string> result;
        _permutation(str, 0, str.size()-1, result);

        return result;
    }
private: 
    void _permutation(string& str, size_t leftIndex, size_t rightIndex, vector<string>& result)
    {
        if (leftIndex == rightIndex)
        {
            result.push_back(str);
        }
        else  
        {
            for (int index = leftIndex; index < rightIndex; ++index)
            {
                if (leftIndex != index)
                    swap(str[leftIndex], str[index]);
                
                _permutation(str, leftIndex+1, rightIndex, result);

                if (leftIndex != index)
                    swap(str[leftIndex], str[index]);    
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
    vector<string> res = s.Permutation("abcde");
    for (auto &v : res)
        std::cout << v << "\n";
    std::cout << std::endl;
    return 0;
}
