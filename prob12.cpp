
#include <iostream>
#include <string>

using std::string;

/*
* Name: 12. Integer to Roman
* Description: 
* Given an integer, convert it to a roman numeral.
* Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
    string intToRoman(int num) {
        
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}

/* 
class Solution {
public:
    /*
    * Runtime: 99 ms
    * Your runtime beats 5.95 % of cpp submissions. 
    */
    string intToRoman(int num) {
        
        if (num < 10)
            return tentoroman(num);
        else {
            auto mfind = other.find(num);
            if (mfind == other.end()) {
                if (num < 100) {
                    return hundredtoroman(num);
                } else if (num < 1000) {
                    return thousandtoroman(num);
                } else {
                    return othertoroman(num);
                }
            } else {
                return mfind->second;
            }
        }
    }
private:
    const std::vector<std::string> base = {"","I", "II", "III", "IV", "V", "VI","VII", "VIII", "IX"}; 
    const std::map<int, std::string> other = {
        {10,"X"},{40, "XL"},{50, "L"},{90, "XC"},{100, "C"},{400, "CD"},{500,"D"},{900, "CM"},{1000,"M"}};
    
    string tentoroman(int num) {
        return base[num];
    }
    string hundredtoroman(int num) {
        
        string ret = "";
        int left = num/10;
        int right = num%10;
        
        if (left < 4) {
            for (int i = 0; i < left; ++i) {
                ret += "X";
            }
        } else if (left < 5) {
            ret += "XL";
        } else if (left < 9) {
            ret += "L";
            for (int i = 0; i < left-5; ++i) {
                ret += "X";
            }            
        } else {
            ret += "XC";            
        }
        
        return ret + tentoroman(right);
    }
    string thousandtoroman(int num) {
        
        string ret = "";
        int left = num/100;
        int right = num%100;
        
        if (left < 4) {
            for (int i = 0; i < left; ++i) {
                ret += "C";
            }
        } else if (left < 5) {
            ret += "CD";
        } else if (left < 9) {
            ret += "D";
            for (int i = 0; i < left-5; ++i) {
                ret += "C";
            }            
        } else {
            ret += "CM";            
        }
        
        return ret + hundredtoroman(right);
    }
    string othertoroman(int num) {
        
        string ret = "";
        int left = num/1000;
        int right = num%1000;
        

        for (int i = 0; i < left; ++i) {
            ret += "M";
        }
        return ret + thousandtoroman(right);
    }    
    
    
};
*/