
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iterator>
#include <unordered_set>
#include <cmath>
#include <cctype>

#include "gtest/gtest.h"

using namespace std;
/*
* Name: 507. Perfect Number
* WebSite: https://leetcode.com/problems/perfect-number/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    bool checkPerfectNumber_v2(int num) {
        if (num <= 5) return false;
        std::unordered_set<int> divisors = {1};
        int sqrtNum = static_cast<int>(std::sqrt(num));
        int quotient = 0;
        for (int i = 2; i <= sqrtNum; ++i) {
            if (divisors.find(i) == divisors.end()) {
                if (num % i == 0) {
                    quotient = num / i;
                    divisors.insert({i, quotient});
                    for (int j = i * 2; j <= sqrtNum; j *= 2) {
                        quotient = num / j;
                        divisors.insert({j, quotient});
                    }
                }
            }
        }
        int sum = std::accumulate(divisors.begin(), divisors.end(), 0);    
        return (sum == num);
    }
    bool checkPerfectNumber(int num) {
        if(num <= 1) return 0;
        int sum = 1;
        for(int i=2; i < sqrt(num); ++i){
            if(num % i == 0 ) {
                sum += i + (num/i);
            }
        }
        return sum == num;
    }

    // Approach #4 Euclid-Euler Theorem
    // https://leetcode.com/problems/perfect-number/solution/ 
    bool checkPerfectNumber4(int num) 
    {
        auto pn = [](int p) -> int { return (1<<(p-1)) * ((1<<p)-1); };
        vector<int> primes = {2,3,5,7,13,17,19,31};
        for (int prime : primes) {
            if (pn(prime) == num)
                return true;
        }
        return false;
    }
};


Solution solu; 

TEST(CheckPerfectNumberTest, Negative)
{
    EXPECT_FALSE(solu.checkPerfectNumber(-1));
    EXPECT_FALSE(solu.checkPerfectNumber(-11));
}

TEST(CheckPerfectNumberTest, Zero)
{
    EXPECT_FALSE(solu.checkPerfectNumber(0));
}
TEST(CheckPerfectNumberTest, Positive) 
{
    EXPECT_FALSE(solu.checkPerfectNumber(1));
    EXPECT_FALSE(solu.checkPerfectNumber(2));
    EXPECT_FALSE(solu.checkPerfectNumber(3));

    EXPECT_TRUE(solu.checkPerfectNumber(28));
    EXPECT_FALSE(solu.checkPerfectNumber(36));
}

              