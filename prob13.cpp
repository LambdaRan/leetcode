
#include <iostream>
#include <string>
#include <map>

/*
* Name: 13. Roman to Integer
* Description: 
* Given a roman numeral, convert it to an integer.
* Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
    /*
    * Runtime:  88  ms
    * Your runtime beats 36.40 % of cpp submissions. 
    */
    int romanToInt(std::string s) {
        
        if (s.size()<=0) return 0;
        const std::map<char, int> base = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int sum = 0;
        for (unsigned int i = 0; i != s.length()-1; ++i) {
            sum += base.at(s[i]) < base.at(s[i+1]) ? (-base.at(s[i])) : base.at(s[i]);
        }
        sum += base.at(s[s.length()-1]);

        return sum;
    }
    /*
    * Runtime:  69  ms
    * Your runtime beats 66.29 % of cpp submissions. 
    */
    int romanToInt2(std::string s) {

        if (s.size()<=0) return 0;

        int result = romanCharToInt(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            int prev = romanCharToInt(s[i-1]);
            int curr = romanCharToInt(s[i]);
            //if left<right such as : IV(4), XL(40), IX(9) ...
            if (prev < curr) {
                result = result - prev + (curr-prev);
            }else{
                result += curr;
            }
        }
        return result;

    }
private:
    int romanCharToInt(char ch){
        int d = 0;
        switch (ch) {
            case 'I':  d = 1;  break;  
            case 'V':  d = 5;  break;  
            case 'X':  d = 10;  break;  
            case 'L':  d = 50;  break;  
            case 'C':  d = 100;  break;  
            case 'D':  d = 500;  break;  
            case 'M':  d = 1000;  break;  
        }
        return d;
    }

};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout <<  "intToRoman(III): expect: 3 <------>  " << s.romanToInt("III") << "\n";
    std::cout <<  "intToRoman(IV): expect: 4 <------>  " << s.romanToInt("IV") << "\n";
    std::cout <<  "intToRoman(VIII): expect:  8<------>  " << s.romanToInt("VIII") << "\n";    
    std::cout <<  "intToRoman(XI): expect:  11<------>  " << s.romanToInt("XI") << "\n";
    std::cout <<  "intToRoman(XXIII): expect:  23<------>  " << s.romanToInt("XXIII") << "\n";
    std::cout <<  "intToRoman(LXVII): expect:  67<------>  " << s.romanToInt("LXVII") << "\n";
    std::cout <<  "intToRoman(CXXVI): expect:  126<------>  " << s.romanToInt("CXXVI") << "\n";
    std::cout <<  "intToRoman(CDXXXIX): expect:  439<------>  " << s.romanToInt("CDXXXIX") << "\n";
    std::cout <<  "intToRoman(D): expect: 500 <------>  " << s.romanToInt("D") << "\n";
    std::cout <<  "intToRoman(DCCXLVIII): expect:  748<------>  " << s.romanToInt("DCCXLVIII") << "\n";
    std::cout <<  "intToRoman(MCCXXXIV): expect:  1234<------>  " << s.romanToInt("MCCXXXIV") << "\n";
    std::cout <<  "intToRoman(MMDCLXXIX): expect:  2679<------>  " << s.romanToInt("MMDCLXXIX") << "\n";
    std::cout <<  "intToRoman(MMMCMXCIX): expect:  3999<------>  " << s.romanToInt("MMMCMXCIX") << "\n";
    std::cout << "method 2: \n";
    std::cout <<  "intToRoman2(III): expect: 3 <------>  " << s.romanToInt2("III") << "\n";
    std::cout <<  "intToRoman2(IV): expect: 4 <------>  " << s.romanToInt2("IV") << "\n";
    std::cout <<  "intToRoman2(VIII): expect:  8<------>  " << s.romanToInt2("VIII") << "\n";    
    std::cout <<  "intToRoman2(XI): expect:  11<------>  " << s.romanToInt2("XI") << "\n";
    std::cout <<  "intToRoman2(XXIII): expect:  23<------>  " << s.romanToInt2("XXIII") << "\n";
    std::cout <<  "intToRoman2(LXVII): expect:  67<------>  " << s.romanToInt2("LXVII") << "\n";
    std::cout <<  "intToRoman2(CXXVI): expect:  126<------>  " << s.romanToInt2("CXXVI") << "\n";
    std::cout <<  "intToRoman2(CDXXXIX): expect:  439<------>  " << s.romanToInt2("CDXXXIX") << "\n";
    std::cout <<  "intToRoman2(D): expect: 500 <------>  " << s.romanToInt2("D") << "\n";
    std::cout <<  "intToRoman2(DCCXLVIII): expect:  748<------>  " << s.romanToInt2("DCCXLVIII") << "\n";
    std::cout <<  "intToRoman2(MCCXXXIV): expect:  1234<------>  " << s.romanToInt2("MCCXXXIV") << "\n";
    std::cout <<  "intToRoman2(MMDCLXXIX): expect:  2679<------>  " << s.romanToInt2("MMDCLXXIX") << "\n";
    std::cout <<  "intToRoman2(MMMCMXCIX): expect:  3999<------>  " << s.romanToInt2("MMMCMXCIX") << "\n";
    std::cout << std::endl;
    return 0;
}