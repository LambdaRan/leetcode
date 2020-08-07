#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 599. Minimum Index Sum of Two Lists
// Website: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
// Description:

class Solution {
public:

    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::vector<string>& minl = list1.size() < list2.size() ? list1 : list2;
        std::vector<string>& maxl = list1.size() < list2.size() ? list2 : list1;
        std::unordered_map<string, int> mp(minl.size());
        for (size_t idx = 0; idx < minl.size(); ++idx) {
            mp[minl[idx]] = idx;
        }
        std::vector<std::pair<int, std::string>> common;
        for (size_t idx = 0; idx < maxl.size(); ++idx) {
            const auto it = mp.find(maxl[idx]);
            if (it != mp.end()) {
                common.emplace_back(std::make_pair(idx + it->second, it->first));
            }
        }
        const auto min_it = std::min_element(common.begin(), common.end(),
                                         [](const std::pair<int, std::string>& lhs, const std::pair<int, std::string>& rhs) { return lhs.first < rhs.first; });
        std::vector<std::string> result;
        for (const auto& pair : common) {
            if (pair.first == min_it->first) {
                result.emplace_back(pair.second);
            }
        }
        return result;
        // size_t min_index_sum = minl.size() + maxl.size();
        // std::vector<std::string> result;
        // for (const auto& pair : common) {
        //     if (pair.first < min_index_sum) {
        //         result.clear();
        //         result.emplace_back(pair.second);
        //         min_index_sum = pair.first;
        //     } else if (pair.first == min_index_sum) {
        //         result.emplace_back(pair.second);
        //     } else {
        //         // nothing
        //     }
        // }
        // return result;
        // std::sort(common.begin(), common.end(),
        //           [](const std::pair<int, std::string>& lhs, const std::pair<int, std::string>& rhs) { return lhs.first < rhs.first; });
        // std::vector<std::string> result {common[0].second};
        // for (size_t idx = 1; idx < common.size(); ++idx) {
        //     if (common[idx].first == common[0].first) {
        //         result.emplace_back(common[idx].second);
        //     }
        // }
        // return result;
    }

};

Solution solu;

// TEST(Fuction, one) {}