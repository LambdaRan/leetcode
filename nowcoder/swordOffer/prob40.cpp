
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

/*
* Name: 数组中只出现一次的数字
* Description: 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*
*/

TODO 看编程之美，有一道相仿的题（1.5 找出故障机器）
class Solution {
public:
    void FindNumsAppearOnce(vector<int>& data,int* num1,int *num2) {

        if (data.size() < 2) return;
        *num1 = 0; *num2 = 0;
        std::unordered_map<int, int> dataUnorderMap;
        for (int v : data)
        {
            ++dataUnorderMap[v];
        }
        std::cout << "next find" << "\n";
        for (const std::pair<int, int>& element : dataUnorderMap)
        {
            if (element.second == 1)
            {
                if (*num1 == 0)
                    *num1 = element.first;
                else  
                    *num2 = element.first;
            }
        };
    }
};

int main() 
{
    Solution s;
    vector<int> vec = {3,5,4,7,6,3,4,5};
    int num1 = 0;
    int num2 = 0;
    std::cout << "method 1: \n";
    s.FindNumsAppearOnce(vec, &num1, &num2);
    std::cout << "num1: " << num1 << " num2: " << num2;
    std::cout << std::endl;
    return 0;
}
