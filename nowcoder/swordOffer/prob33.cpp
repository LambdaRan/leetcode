
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 丑数
* Description: 把只包含因子2、3和5的数称作丑数（Ugly Number）。
* 例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。
* 求按从小到大的顺序的第N个丑数。
*
*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        
        int par[] = {1,2,3,4,5,6,8,9,10};
        if (index <= sizeof(par)/sizeof(par[0]))
            return par[index-1];
        
        int count = sizeof(par)/sizeof(par[0]);
        int start = ++par[count-1];
        int lastUglyNumber = par[count-1];
        while (count < index)
        {
            if (isUglyNumber(start))
            {
                ++count;
                lastUglyNumber = start;
            }
            ++start;
        }
        return lastUglyNumber;
    }
private: 
    bool isUglyNumber(int value)
    {
        int base[] = {2,5,3};
        for (int i = 0; i < 3; ++i)
        {
            int quotient = value / base[i];
            int remain = value % base[i];
            while (remain == 0)
            {
                value = quotient;
                quotient = value /base[i];
                remain = value % base[i];
            }
        }
        return value == 1;
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << "UglyNumber index 32 is : " << s.GetUglyNumber_Solution(32);
    std::cout << std::endl;
    return 0;
}
