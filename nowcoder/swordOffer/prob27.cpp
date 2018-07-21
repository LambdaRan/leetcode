

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>

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
        size_t strSize = str.size();
        if (strSize == 1) 
        {
            vector<string> ret;
            ret.push_back(str);
            return ret;
        } 
        
        set<string> result;
        result.insert(str);
        bool loop = true;
        while (loop)
        {
            size_t head = strSize - 1;
            while (true)
            {
                size_t tailOne = head;
                // 找到左边字符小于右边字符位置
                // 如：1，4，5，3，2 
                // head：4  tailOne:5
                if (str[--head] < str[tailOne]) 
                {
                    size_t tailTwo = strSize;
                    // 从右到左找到第一个大于head所指字符的位置
                    // 如：1，4，5，3，2
                    // head:4   tailTwo:5
                    while (!(str[head] < str[--tailTwo]));

                    std::swap(str[head], str[tailTwo]);
                    std::reverse(str.begin()+tailOne, str.end());
                    
                    result.insert(str);
                    break;
                }

                if (head == 0)
                {
                    std::reverse(str.begin(), str.end());
                    loop = false;
                    break;
                }
            }
        }
        return vector<string>(result.begin(), result.end());
    }
public:
    vector<string> Permutation_Recursive(string str) 
    {
        if (str.empty()) return vector<string>();

        set<string> result;
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
    vector<string> res = s.Permutation("a");
    for (auto &v : res)
        std::cout << v << "\n";
    std::cout << std::endl;
    return 0;
}
