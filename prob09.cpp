
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class Solution {
public:
    // 转换成字符串，比较每一位 这个是错误的，不符合要求：Do this without extra space.
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
    // 计算得到整数的开头与结尾的数字，然后比较
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

    // 2018-01-27 23:25:11
    // 方法四：左右计算一半 
    // 开始的时候忽略了一个问题，就是输入的整数如果最后一位都是零，也就是能被10整除，总是判断为是回文，这是错误的，
    // 解决办法; 开始的时候判断是否能被10整除
    bool isPalindrome4(int x) {

        if (x < 0 || (x%10 == 0 && x != 0)) // (x%10 == 0 && x != 0) 很重要
            return false;
        if (x < 10)
            return true;
        
        int rvalue = 0;
        while (x > rvalue) {
            rvalue = rvalue * 10 + x % 10;
            x /= 10;
        }
        return (x == rvalue || x == rvalue/10);
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
    std::cout <<  "10 is palindrome: " << (s.isPalindrome1(10)? "true":"false") << "\n";
    std::cout <<  "-101 is palindrome: " << (s.isPalindrome1(-101)? "true":"false") << "\n";
    std::cout <<  "1001 is palindrome: " << (s.isPalindrome1(1001)? "true":"false") << "\n";
    std::cout <<  "1234321 is palindrome: " << (s.isPalindrome1(1234321)? "true":"false") << "\n";
    std::cout <<  "2147447412 is palindrome: " << (s.isPalindrome1(2147447412)? "true":"false") << "\n";
    std::cout <<  "2142 is palindrome: " << (s.isPalindrome1(2142)? "true":"false") << "\n";

    std::cout << "method 2: \n";
    std::cout <<  "0 is palindrome: " << (s.isPalindrome2(0)? "true":"false") << "\n";
    std::cout <<  "10 is palindrome: " << (s.isPalindrome2(10)? "true":"false") << "\n";
    std::cout <<  "100 is palindrome: " << (s.isPalindrome2(100)? "true":"false") << "\n";
    std::cout <<  "20 is palindrome: " << (s.isPalindrome2(20)? "true":"false") << "\n";
    std::cout <<  "21120 is palindrome: " << (s.isPalindrome2(21120)? "true":"false") << "\n";    
    std::cout <<  "9000 is palindrome: " << (s.isPalindrome2(9000)? "true":"false") << "\n";
    std::cout <<  "-101 is palindrome: " << (s.isPalindrome2(-101)? "true":"false") << "\n";
    std::cout <<  "1001 is palindrome: " << (s.isPalindrome2(1001)? "true":"false") << "\n";
    std::cout <<  "1234321 is palindrome: " << (s.isPalindrome2(1234321)? "true":"false") << "\n";
    std::cout <<  "2147447412 is palindrome: " << (s.isPalindrome2(2147447412)? "true":"false") << "\n";
    std::cout <<  "2142 is palindrome: " << (s.isPalindrome2(2142)? "true":"false") << "\n";

    std::cout << "method 4: \n";
    std::cout <<  "0 is palindrome: " << (s.isPalindrome4(0)? "true":"false") << "\n";
    std::cout <<  "10 is palindrome: " << (s.isPalindrome4(10)? "true":"false") << "\n";
    std::cout <<  "100 is palindrome: " << (s.isPalindrome4(100)? "true":"false") << "\n";
    std::cout <<  "20 is palindrome: " << (s.isPalindrome4(20)? "true":"false") << "\n";
    std::cout <<  "21120 is palindrome: " << (s.isPalindrome4(21120)? "true":"false") << "\n";
    std::cout <<  "9000 is palindrome: " << (s.isPalindrome4(9000)? "true":"false") << "\n";
    std::cout <<  "-101 is palindrome: " << (s.isPalindrome4(-101)? "true":"false") << "\n";
    std::cout <<  "1001 is palindrome: " << (s.isPalindrome4(1001)? "true":"false") << "\n";
    std::cout <<  "1234321 is palindrome: " << (s.isPalindrome4(1234321)? "true":"false") << "\n";
    std::cout <<  "2147447412 is palindrome: " << (s.isPalindrome4(2147447412)? "true":"false") << "\n";
    std::cout <<  "2142 is palindrome: " << (s.isPalindrome4(2142)? "true":"false") << "\n";


    std::cout << std::endl;
    
    return 0;
}