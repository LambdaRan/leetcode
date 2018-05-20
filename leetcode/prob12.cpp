
#include <iostream>
#include <string>
#include <vector>
#include <utility> /* std::pair<> */


/*
* Name: 12. Integer to Roman
* Description: 
* Given an integer, convert it to a roman numeral.
* Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
    /*
    * Runtime:  61  ms
    * Your runtime beats 61.73 % of cpp submissions. 
    */
    std::string intToRoman(int num) {
        
        const std::vector<std::pair<int, std::string> > m_base = {
            {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40, "XL"},{50, "L"},{90, "XC"},{100, "C"},{400, "CD"},{500,"D"},{900, "CM"},{1000,"M"}
        };        
        int _endindex = static_cast<int>(m_base.size() - 1);
        std::string ret;

        while (num > 0) {
            // 记录：由 while(num < m_base[_endindex].first < 0 && _endindex >= 0) 改为
            // while(num < m_base[_endindex].first && _endindex >= 0) {}
            // 运行时间从 119ms 提升到 61ms
            while(num < m_base[_endindex].first && _endindex >= 0) {
                --_endindex;
            }

            ret += m_base[_endindex].second;
            num -= m_base[_endindex].first;
        }
        return ret;
    }
    /*
    * Runtime:  87  ms
    * Your runtime beats 16.90 % of cpp submissions. 
    * reference
    */   
    std::string intToRoman2(int num) {
        std::string M[] = {"", "M", "MM", "MMM"};
        std::string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        std::string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        std::string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout <<  "intToRoman(3): expect: III <------>  " << s.intToRoman(3) << "\n";
    std::cout <<  "intToRoman(4): expect: IV <------>  " << s.intToRoman(4) << "\n";
    std::cout <<  "intToRoman(8): expect: VIII <------>  " << s.intToRoman(8) << "\n";    
    std::cout <<  "intToRoman(11): expect: XI <------>  " << s.intToRoman(11) << "\n";
    std::cout <<  "intToRoman(23): expect: XXIII <------>  " << s.intToRoman(23) << "\n";
    std::cout <<  "intToRoman(67): expect: LXVII <------>  " << s.intToRoman(67) << "\n";
    std::cout <<  "intToRoman(126): expect: CXXVI <------>  " << s.intToRoman(126) << "\n";
    std::cout <<  "intToRoman(439): expect: CDXXXIX <------>  " << s.intToRoman(439) << "\n";
    std::cout <<  "intToRoman(500): expect: D <------>  " << s.intToRoman(500) << "\n";
    std::cout <<  "intToRoman(748): expect: DCCXLVIII <------>  " << s.intToRoman(748) << "\n";
    std::cout <<  "intToRoman(1234): expect: MCCXXXIV <------>  " << s.intToRoman(1234) << "\n";
    std::cout <<  "intToRoman(2679): expect: MMDCLXXIX <------>  " << s.intToRoman(2679) << "\n";
    std::cout <<  "intToRoman(3999): expect: MMMCMXCIX <------>  " << s.intToRoman(3999) << "\n";
    std::cout << "method 2: \n";
    std::cout <<  "intToRoman2(3): expect: III <------>  " << s.intToRoman2(3) << "\n";
    std::cout <<  "intToRoman2(4): expect: IV <------>  " << s.intToRoman2(4) << "\n";
    std::cout <<  "intToRoman2(8): expect: VIII <------>  " << s.intToRoman2(8) << "\n";    
    std::cout <<  "intToRoman2(11): expect: XI <------>  " << s.intToRoman2(11) << "\n";
    std::cout <<  "intToRoman2(23): expect: XXIII <------>  " << s.intToRoman2(23) << "\n";
    std::cout <<  "intToRoman2(67): expect: LXVII <------>  " << s.intToRoman2(67) << "\n";
    std::cout <<  "intToRoman2(126): expect: CXXVI <------>  " << s.intToRoman2(126) << "\n";
    std::cout <<  "intToRoman2(439): expect: CDXXXIX <------>  " << s.intToRoman2(439) << "\n";
    std::cout <<  "intToRoman2(500): expect: D <------>  " << s.intToRoman2(500) << "\n";
    std::cout <<  "intToRoman2(748): expect: DCCXLVIII <------>  " << s.intToRoman2(748) << "\n";
    std::cout <<  "intToRoman2(1234): expect: MCCXXXIV <------>  " << s.intToRoman2(1234) << "\n";
    std::cout <<  "intToRoman2(2679): expect: MMDCLXXIX <------>  " << s.intToRoman2(2679) << "\n";
    std::cout <<  "intToRoman2(3999): expect: MMMCMXCIX <------>  " << s.intToRoman2(3999) << "\n";
    std::cout << std::endl;
    return 0;
}

 
// class Solution {
// public:
//     /*
//     * Runtime: 99 ms
//     * Your runtime beats 5.95 % of cpp submissions. 
//     */
//     string intToRoman(int num) {
        
//         if (num < 10)
//             return tentoroman(num);
//         else {
//             auto mfind = other.find(num);
//             if (mfind == other.end()) {
//                 if (num < 100) {
//                     return hundredtoroman(num);
//                 } else if (num < 1000) {
//                     return thousandtoroman(num);
//                 } else {
//                     return othertoroman(num);
//                 }
//             } else {
//                 return mfind->second;
//             }
//         }
//     }
// private:
//     const std::vector<std::string> base = {"","I", "II", "III", "IV", "V", "VI","VII", "VIII", "IX"}; 
//     const std::map<int, std::string> other = {
//         {10,"X"},{40, "XL"},{50, "L"},{90, "XC"},{100, "C"},{400, "CD"},{500,"D"},{900, "CM"},{1000,"M"}};
    
//     string tentoroman(int num) {
//         return base[num];
//     }
//     string hundredtoroman(int num) {
        
//         string ret = "";
//         int left = num/10;
//         int right = num%10;
        
//         if (left < 4) {
//             for (int i = 0; i < left; ++i) {
//                 ret += "X";
//             }
//         } else if (left < 5) {
//             ret += "XL";
//         } else if (left < 9) {
//             ret += "L";
//             for (int i = 0; i < left-5; ++i) {
//                 ret += "X";
//             }            
//         } else {
//             ret += "XC";            
//         }
        
//         return ret + tentoroman(right);
//     }
//     string thousandtoroman(int num) {
        
//         string ret = "";
//         int left = num/100;
//         int right = num%100;
        
//         if (left < 4) {
//             for (int i = 0; i < left; ++i) {
//                 ret += "C";
//             }
//         } else if (left < 5) {
//             ret += "CD";
//         } else if (left < 9) {
//             ret += "D";
//             for (int i = 0; i < left-5; ++i) {
//                 ret += "C";
//             }            
//         } else {
//             ret += "CM";            
//         }
        
//         return ret + hundredtoroman(right);
//     }
//     string othertoroman(int num) {
        
//         string ret = "";
//         int left = num/1000;
//         int right = num%1000;
        

//         for (int i = 0; i < left; ++i) {
//             ret += "M";
//         }
//         return ret + thousandtoroman(right);
//     }    
    
    
// };
