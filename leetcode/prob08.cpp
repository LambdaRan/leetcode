

#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <cassert>

using std::string;
using std::cin;
using std::cout;


class Solution {
public:
    int myAtoi(string str) {
        
        int c;
        int index;
        int neg;

        int ret=0;

        if (str.empty())
            return 0;
        /* 清除开头的空格 */
        index = 0;
        do {
            c = str[index++];
        } while(isspace(c));
        /* 判断符号 */
        if (c == '-') {
            neg = 1;
            c = str[index++];
        } else {
            neg = 0;
            if (c == '+')
                c = str[index++];
        }
        for (;isdigit(c); c = str[index++]) {
            int digit = c - '0';
            if (neg) {
                if (-ret < (INT_MIN + digit)/10)
                return INT_MIN;
            } else {
                if (ret > (INT_MAX - digit)/10)
                return INT_MAX;
            }

            ret = ret * 10 + digit;
        }

        return neg ? -ret : ret;
    }

    const int INT_MAX = 2147483647;
    const int INT_MIN = -2147483648;
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (size_t i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    // string line;
    // while (getline(cin, line)) {
    //     string str = stringToString(line);
        
    //     int ret = Solution().myAtoi(str);

    //     string out = to_string(ret);
    //     cout << out << endl;
    // }
    printf("\"%s\" = %d\n", "123", Solution().myAtoi("123"));
    printf("\"%s\" = %d\n", "   123", Solution().myAtoi("    123"));
    printf("\"%s\" = %d\n", "+123", Solution().myAtoi("+123"));
    printf("\"%s\" = %d\n", " -123", Solution().myAtoi(" -123"));
    printf("\"%s\" = %d\n", "123ABC", Solution().myAtoi("123ABC"));
    printf("\"%s\" = %d\n", " abc123ABC", Solution().myAtoi(" abc123ABC"));
    printf("\"%s\" = %d\n", "2147483647", Solution().myAtoi("2147483647"));
    printf("\"%s\" = %d\n", "-2147483648", Solution().myAtoi("-2147483648"));
    printf("\"%s\" = %d\n", "2147483648", Solution().myAtoi("2147483648"));
    printf("\"%s\" = %d\n", "-2147483649", Solution().myAtoi("-2147483649"));
    return 0;
}