
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
* Name: 219. Contains Duplicate II
* Website: https://leetcode.com/problems/contains-duplicate-ii/description/
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> values;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        {
            if (values.find(nums[i]) != values.end() && i-values[nums[i]] <= k)
                return true;
            values[nums[i]] = i;
        }
        return false; 
    }

    bool containsNearbyDuplicate_v1(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> valuesToIndex;
        for (size_t i = 0; i < nums.size(); ++i)
            valuesToIndex[nums[i]].emplace_back(i);
        for (auto it = valuesToIndex.begin(); it != valuesToIndex.end(); ++it)
        {
            if (it->second.size() > 1)
            {
                auto vec = it->second;
                for (size_t i = 1; i < vec.size(); ++i)
                {
                    if (vec[i] - vec[i-1] <= k) return true;
                }
            }
        }
        return false; 
    }
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        bool ret = Solution().containsNearbyDuplicate(nums, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}