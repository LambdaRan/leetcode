
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
/*
* Name: 367. Valid Perfect Square
* Website: https://leetcode.com/problems/valid-perfect-square/description/
* Description: 
*
*/
class Solution
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    // 参考 69
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        
        int left = 1;
        int right = num/2;
        int result = 0;
        while (true)
        {
            int mid = left + (right-left)/2;
            if (mid > num/mid)
                right = mid - 1;
            else  
            {
                if ((mid+1) > num/(mid+1))
                {
                    result = mid;
                    break;
                }
                left = mid + 1;
            }
        }
        
        return result*result == num? true : false;
    }
    //  https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
    // https://en.wikipedia.org/wiki/Newton%27s_method
    bool isPerfectSquare(int num) {
        long x = static_cast<long>(num);
        while (x * x > num) {
            x = (x + num / x) >> 1;
        }
        return x * x == num;
    }
};

int main()
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}