#include <iostream>
#include <string>
#include <unordered_map>

#include "gtest/gtest.h"

using namespace std;

// Name: 551. Student Attendance Record I
// Website: https://leetcode.com/problems/student-attendance-record-i/
// Description:

class Solution {
public:
    bool checkRecord(string s) {
        uint32_t p_count = 0;
        uint32_t a_count = 0;
        for (char c : s) {
            if (c == 'A') {
                ++a_count;
                if (a_count > 1) {
                    return false;
                }
            }
            if (c == 'L') {
                ++p_count;
                if (p_count > 2) {
                    return false;
                }
            } else {
                p_count = 0;
            }
        }
        return true;
    }
};


Solution solu;

TEST(checkRecord, empty)
{
    string line = "";
    EXPECT_TRUE(solu.checkRecord(line));
}

TEST(checkRecord, absent) {
    string line = "PPPAPPLL";
    EXPECT_TRUE(solu.checkRecord(line));

    line = "PAPLLPAP";
    EXPECT_FALSE(solu.checkRecord(line));
}

TEST(checkRecord, late) {
    string line = "PPPAPPLLLL";
    EXPECT_FALSE(solu.checkRecord(line));
}
