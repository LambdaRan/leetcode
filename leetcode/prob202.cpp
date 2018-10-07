
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
* Name: 202. Happy Number
* Website: https://leetcode.com/problems/happy-number/description/
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
    bool isHappy(int n) {
        unordered_set<int> base = {1,7,10,13,19,23,28,31,32,44,49,68,70,79,82,86,91,94,97,100};
        while (n > 100) n = digitSquareSum(n);
        return base.find(n) != base.end();
    }
    int digitSquareSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int remain = n % 10;
            sum += remain * remain;
            n /= 10;
        }
        return sum;
    }
/****************/
    // Floyd Cycle detection algorithm
    bool isHappy_v2(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while(slow != fast);

        if (slow == 1) return true;
        else return false;
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}