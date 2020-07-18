#include <iostream>
#include <string>
#include <unordered_set>
#include <bitset>
#include "gtest/gtest.h"

using namespace std;

// Name:
// Website:
// Description:

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        std::unordered_set<int> single(candies.begin(), candies.end());
        return std::min(single.size(), candies.size()/2);
    }
    int distributeCandies_v2(vector<int>& candies) {
        std::bitset<200001> hash;
        for (int v : candies) {
            hash.set(v + 100000);
        }
        return std::min(hash.count(), candies.size()/2);
    }
};

Solution solu;

// TEST(Fuction, one) {}