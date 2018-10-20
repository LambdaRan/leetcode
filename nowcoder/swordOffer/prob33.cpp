
#include <iostream>
#include <algorithm>
#include <vector>

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
    int GetUglyNumber_Solution(int index) 
    {
        if (index < 7) return index;
        std::vector<int> oldUglyNumber(index);
        oldUglyNumber[0] = 1;
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;

        for (int i = 1; i < index; ++i)
        {
            oldUglyNumber[i] = std::min({oldUglyNumber[index2] * 2,
                                        oldUglyNumber[index3] * 3,
                                        oldUglyNumber[index5] * 5});
            if (oldUglyNumber[i] == oldUglyNumber[index2] * 2)
                ++index2;
            if (oldUglyNumber[i] == oldUglyNumber[index3] * 3)
                ++index3;
            if (oldUglyNumber[i] == oldUglyNumber[index5] * 5)
                ++index5;
        }
        return oldUglyNumber[index-1];
    }
    // time out
    int GetUglyNumber_Solution_laji(int index) {
        
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
        if (value <= 0) return false;
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
