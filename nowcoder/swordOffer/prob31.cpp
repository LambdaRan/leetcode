
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 整数中1出现的次数（从1到n整数中1出现的次数）
* Description: 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
* 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
* ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*
*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        size_t iCount = 0;
        size_t iFactor = 1;
        size_t iLowerNum = 0;
        size_t iCurrNum = 0;
        size_t iHigherNum = 0;

        while (n / iFactor != 0)
        {
            iLowerNum = n - (n/iFactor) * iFactor;
            iCurrNum = (n/iFactor) % 10;
            iHigherNum = n / (iFactor*10);

            switch(iCurrNum)
            {
                case 0:
                    iCount += iHigherNum * iFactor;
                    break;
                case 1:
                    iCount += iHigherNum * iFactor + iLowerNum + 1;
                    break;
                default:
                    iCount += (iHigherNum + 1) * iFactor;
                    break;
            }
            iFactor *= 10;
        }
        return iCount;
    }
};
int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
