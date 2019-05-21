
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <cctype>

#include "gtest/gtest.h"

using namespace std;
/*
* Name: 506. Relative Ranks
* WebSite: https://leetcode.com/problems/relative-ranks/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.empty()) return vector<string>();
        
        vector<int> ranks(nums);
        std::sort(ranks.begin(), ranks.end(), std::greater<int>());
        unordered_map<int, size_t> numToRanks(nums.size());
        for (size_t i = 0; i < ranks.size(); ++i) {
            numToRanks[ranks[i]] = i+1;
        }
        vector<string> result(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
           switch (numToRanks[nums[i]])
           {
            case 1:
                result[i] = "Gold Medal";
                break;
            case 2:
                result[i] = "Silver Medal";
                break;
            case 3:
                result[i] = "Bronze Medal";
                break;
            default:
                result[i] = std::to_string(numToRanks[nums[i]]);
                break;
           } 
        }
        return result;
    }
    vector<string> findRelativeRanks_2(vector<int>& nums) {
       vector<string> result(nums.size(),"");
        if(nums.empty()) return result;
        else if(nums.size() == 1){
            result[0] = "Gold Medal";
            return result;
        }
        else if(nums.size()== 2){
            if(nums[0] > nums[1]){
                result[0] = "Gold Medal";
                result[1] = "Silver Medal";
            }
            else{
                result[0] = "Silver Medal";
                result[1] = "Gold Medal";
            }
            return result;
        }

        using Entry = std::pair<size_t, int>;

        vector<Entry> ranks(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            ranks[i].first = i;
            ranks[i].second = nums[i];
        }
        auto ranksComp = [](const Entry & lv, const Entry &rv) { return lv.second > rv.second; };
        std::sort(ranks.begin(), ranks.end(), ranksComp);
       
        result[ranks[0].first] = "Gold Medal";
        result[ranks[1].first] = "Silver Medal";
        result[ranks[2].first] = "Bronze Medal";
        for (size_t i = 3; i < ranks.size(); ++i) {
            result[ranks[i].first] = std::to_string(i+1);
        }
        return result;
    }
};


Solution solu; 

TEST(FindRelativeRanksTest, Positive)
{
    vector<int> num = {5, 4, 3, 2, 1};
    vector<string> expected = {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
    vector<string> actual = solu.findRelativeRanks(num);
    EXPECT_EQ(expected, actual);

    vector<int> num2;
    EXPECT_EQ(vector<string>(), solu.findRelativeRanks(num2));
}

TEST(FindRelativeRanksTest2, Positive)
{
    vector<int> num = {5, 4, 3, 2, 1};
    vector<string> expected = {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
    vector<string> actual = solu.findRelativeRanks_2(num);
    EXPECT_EQ(expected, actual);

    vector<int> num2;
    EXPECT_EQ(vector<string>(), solu.findRelativeRanks_2(num2));

    vector<int> num3 = {1};
    EXPECT_EQ(vector<string>{"Gold Medal"}, solu.findRelativeRanks_2(num3));
}

              