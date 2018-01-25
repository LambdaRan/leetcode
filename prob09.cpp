
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class Solution {
public:
    // 转换成字符串，比较每一位
    bool isPalindrome1(int x) {
        
        if (x < 0)
            return false;
        int mval = x;
        std::string istr = std::to_string(mval);
        for (int i = 0, j = istr.size()-1; i < j; ++i, --j) {
            if (istr[i] != istr[j])
                return false;
        }
        return true;
    }
    // 计算得到整数的开头与结尾的数字，饭后比较
    bool isPalindrome2(int x) {

        if (x < 0)
            return false;
        int len = 0;
        for (len = 1; (x/len) >= 10; len *= 10);

        while (x != 0) {
            int left = x / len;
            int right = x % 10;
            if (left != right)
                return false;
            
            x = (x % len) / 10;

            len /= 100;
        }

        return true;
    }
    // 方法三： 颠倒整数然后比较大小。
    // 注意：颠倒整数溢出  有问题
    bool isPalindrome3(int x) {
        return (x>=0 && x == reverse(x));
    }   
private:    
    int reverse(int x) {
        int y=0;

        int n;
        while( x!=0 ){
            n = x%10;
            y = y*10 + n;
            x /= 10;
        }
        return y;
    }    
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout <<  "0 is palindrome: " << (s.isPalindrome1(0)? "true":"false") << "\n";
    std::cout <<  "-101 is palindrome: " << (s.isPalindrome1(-101)? "true":"false") << "\n";
    std::cout <<  "1001 is palindrome: " << (s.isPalindrome1(1001)? "true":"false") << "\n";
    std::cout <<  "1234321 is palindrome: " << (s.isPalindrome1(1234321)? "true":"false") << "\n";
    std::cout <<  "2147447412 is palindrome: " << (s.isPalindrome1(2147447412)? "true":"false") << "\n";
    std::cout <<  "2142 is palindrome: " << (s.isPalindrome1(2142)? "true":"false") << "\n";

    std::cout << "method 2: \n";
    std::cout <<  "0 is palindrome: " << (s.isPalindrome2(0)? "true":"false") << "\n";
    std::cout <<  "-101 is palindrome: " << (s.isPalindrome2(-101)? "true":"false") << "\n";
    std::cout <<  "1001 is palindrome: " << (s.isPalindrome2(1001)? "true":"false") << "\n";
    std::cout <<  "1234321 is palindrome: " << (s.isPalindrome2(1234321)? "true":"false") << "\n";
    std::cout <<  "2147447412 is palindrome: " << (s.isPalindrome2(2147447412)? "true":"false") << "\n";
    std::cout <<  "2142 is palindrome: " << (s.isPalindrome2(2142)? "true":"false") << "\n";

    std::cout << std::endl;
    
    return 0;
}