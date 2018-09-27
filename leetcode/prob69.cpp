
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 69.Sqrt(x)
* Website: https://leetcode.com/problems/sqrtx/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    // Based on the shift-and-subtract algorithm for computing integer square root from Guy L. Steele.
    int mySqrt_v3(int x) {

        if (x <= 1) return x;
        int m = 1 << (32 - 2);
        int b = 0, y = 0;
        while (m != 0)
        {
            b = y + m;
            y >>= 1;
            if (x >= b)
            {
                x -= b;
                y += m;
            }
            m >>= 2;
        }
        return y;
    }
    int mySqrt_v2(int x) {
        
        if (x == 0) return 0;
        int left = 1;
        int right = x/2;
        while (true)
        {
            int mid = left + (right-left)/2;
            if (mid > x/mid)
                right = mid - 1;
            else  
            {
                if ((mid+1) > x/(mid+1))
                    return mid;
                left = mid + 1;
            }
        }
        //return 0;
    }
    int mySqrt_v0(int x) 
    {
        return sqrt(x);
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}