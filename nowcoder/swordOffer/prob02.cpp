
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;
/*
* 题目描述:
* 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.
* 则经过替换之后的字符串为We%20Are%20Happy。
*
*/
class Solution {
public:
    // 思路： 
    // （1） 统计空格个数，计算新数组长度 new = old + blank * 2；
    // （2） 声明两个指针，P1指向旧数组的尾， P2指向新数组的尾
    // （3） 从尾到头实现复制于替换
    void replaceSpace(char *str, int length)
    {
        if (str == NULL || length <= 0) return;

        // originaLength 为字符串的实际长度
        int originaLength = 0;
        int numberOfBlank = 0;
        int i = 0;
        while (str[i] != '\0')
        {
            ++originaLength;
            if (str[i] == ' ')
                ++numberOfBlank;
            ++i;
        }

        int newLength = originaLength + numberOfBlank * 2;
        if (newLength > length) return;

        int indexOfOriginal = originaLength;
        int indexOfNew = newLength;
        while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
        {
            if (str[indexOfOriginal] == ' ')
            {
                str[indexOfNew--] = '0';
                str[indexOfNew--] = '2';
                str[indexOfNew--] = '%';
            }
            else   
            {
                str[indexOfNew--] = str[indexOfOriginal];
            }
            --indexOfOriginal;
        }
    }


    // 运行时间：6ms
    // 占用内存：756k
	void replaceSpace1(char *str, int length) {
        if (str == NULL) return;

        std::string _str(str, length);
        std::string::size_type ret = _str.find(' ');
        if (ret == std::string::npos) return;
        for(size_t i = ret, index = ret; i < _str.size(); i++)
        {
            if (_str[i] == ' ')
            {
                str[index++] = '%';
                str[index++] = '2';
                str[index++] = '0';
            }
            else  
            {
                str[index++] = _str[i];
            }
        }
	}

    // 运行时间：3ms
    // 占用内存：376k
    void replaceSpace2(char *str,int length) {
        string s(str);
        int i = 0;
        while((i = s.find(' ',i)) != std::string::npos)
        {
            s.erase(i, 1);
            s.insert(i, "%20");
        }
        auto ret = s.c_str();
        ::strcpy(str, ret);
    }
};

int main() 
{
    Solution s;
    char strarray[64] = "hello world string ";
    std::cout << "method 1: \n";

    s.replaceSpace(strarray, static_cast<int>(::strlen(strarray)));
    
    for (size_t i = 0; i < strlen(strarray); ++i)
        std::cout << strarray[i];
    std::cout << std::endl;

    return 0;
}