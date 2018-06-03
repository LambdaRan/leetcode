
#include <iostream>
#include <algorithm>


using namespace std;

/*
* Name: 矩形覆盖
* Description: 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
* 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*
*/
class Solution {
public:
    // 2 * 1 --> 1
    // 2 * 2 --> 2
    // 2 * 3 --> 3
    // 2 * 4 --> 5
    int rectCover(int number) {
        if (number == 0) return 0;

        vector<int> vec(number+1);
        vec[0] = 1;
        vec[1] = 1;
        for (int i = 2; i <= number; ++i)
        {
            vec[i] = vec[i-1] + vec[i-2];
        }
        
        return vec[number];
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    cout << "rectCover(4): 5" << s.rectCover(4);

    std::cout << std::endl;
    return 0;
}