
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
* Name: 509. Fibonacci Number
* WebSite: https://leetcode.com/problems/fibonacci-number/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int fib(int N) {
        if (N <= 1) return N;
        int n_2 = 0;
        int n_1 = 1;
        int fib_n = 0;
        for (int i = 2; i <= N; ++i) {
            fib_n = n_1 + n_2;
            n_2 = n_1;
            n_1 = fib_n;
        }
        return fib_n;
    }
    int fib_v2(int N) {
        if (N < 2) return N;
        int prev = 0, curr = 1;
        for (int i = 2; i <= N; i++) {
            tie(prev, curr) = make_pair(curr, prev + curr);
        }
        return curr;
    }    
};


Solution solu; 


TEST(FibTest, Zero)
{
    EXPECT_EQ(0, solu.fib(0));
}
TEST(FibTest, Positive) 
{
    EXPECT_EQ(1, solu.fib(1));
    EXPECT_EQ(1, solu.fib(2));
    EXPECT_EQ(2, solu.fib(3));
    EXPECT_EQ(5, solu.fib(5));
    EXPECT_EQ(55, solu.fib(10));
}

              