#include <iostream>
#include <string>
#include <iterator>

#include "gtest/gtest.h"

using namespace std;

// Name: 557. Reverse Words in a String III
// Website: https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Description:

class Solution {
public:
    string reverseWords(string s) {
        std::istringstream inbuf(s);
        std::string word;
        std::string result;
        std::string delimiter = "";
        while (inbuf >> word) {
            std::reverse(word.begin(), word.end());
            result += delimiter + word;
            if (delimiter.empty()) {
                delimiter = " ";
            }
        }
        return result;
    }

    string reverseWords2(string s) {
        std::string::size_type pos = 0;
        for (string::size_type idx = 0; idx <= s.size(); ++idx) {
            if (idx == s.size() || s[idx] == ' ') {
                std::reverse(std::next(s.begin(), static_cast<int>(pos)), std::next(s.begin(), static_cast<int>(idx)));
                pos = idx + 1;
            }
        }
        return s;
    }

};

Solution solu;

TEST(reverseWords, one) {
    std::string line = "hello world";
    EXPECT_EQ(solu.reverseWords(line), "olleh dlrow");
}

TEST(reverseWords2, one) {
    std::string line = "hello world";
    EXPECT_EQ(solu.reverseWords2(line), "olleh dlrow");
}
