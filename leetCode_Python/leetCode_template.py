#!/usr/bin/env python3
#-*- coding:utf-8 -*-

class Solution:
    def arrangeCoins(self, n: int) -> int:
        pass

def stringToString(input):
    import json
    return json.loads(input)
# def stringToString(input):
#     return input[1:-1].decode('string_escape')

def stringToIntegerList(input):
    import json
    return json.loads(input)

def stringToInt(input):
    return int(input)

def intToString(input):
    if input is None:
        input = 0
    return str(input)

# def readlines():
#     for line in sys.stdin:
#         yield line.strip('\n')    
def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            n = int(line);
            # s = stringToString(line);
            ret = Solution().arrangeCoins(n)

            out = str(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()
