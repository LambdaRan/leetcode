#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""

"""

# Name:
# Website:
# Description:
import sys

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        dvd, dvs = abs(dividend), abs(divisor)
        ans = 0
        sign = -1 if (dividend > 0) ^ (divisor > 0) else 1
        while dvd >= dvs:
            temp, m = dvs, 1
            while temp << 1 <= dvd:
                temp <<= 1
                m <<= 1
            dvd -= temp
            ans += m
        return sign * ans
    
    if __name__ == "__main__":
        pass