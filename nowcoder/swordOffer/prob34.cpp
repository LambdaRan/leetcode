
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <utility> // std::pair<>

using namespace std;

/*
* Name: 第一个只出现一次的字符
* Description: 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
* 并返回它的位置, 如果没有则返回 -1.
*
*/
class Solution {
public:
    size_t FirstNotRepeatingChar(string str) 
    {
        if (str.empty()) return -1;
        std::map<char, int> charCountMap;
        size_t strSize = str.size();
        for (size_t i = 0; i < strSize; ++i)
        {
            ++charCountMap[str[i]];
        }
        for (size_t i = 0; i < strSize; ++i)
        {
            if (charCountMap[str[i]] == 1)
                return i;
        }
        return -1;
    }
    size_t FirstNotRepeatingChar_laji(string str) {
        
        if (str.empty()) return -1;
        // <字符， <下标， 个数>>
        typedef std::pair<size_t, size_t> ValueType;
        //auto mapCompare = {}(const ){}
        std::map<char, ValueType> indexCharCountMap;

        size_t strSize = str.size();
        for (size_t i = 0; i < strSize; ++i)
        {
            ValueType& value = indexCharCountMap[str[i]];
            if (value.second == 0)
            {
                value.first = i;
            }
            ++value.second;
        }
        std::vector<ValueType> sortVector;
        for (auto &v : indexCharCountMap)
        {
            sortVector.push_back(v.second);
        }
        std::sort(sortVector.begin(), sortVector.end(), [](const ValueType& v1, const ValueType& v2){
            return v1.first < v2.first;
        });
        for (auto& v : sortVector)
        {
            if (v.second == 1)
                return v.first;
        }
        return -1;
    }
};

int main() 
{
    Solution s;
    std::string str = "google";
    std::cout << "method 1: \n";
    std::cout << "google : 4 --> " << s.FirstNotRepeatingChar(str);
    std::cout << std::endl;
    return 0;
}
