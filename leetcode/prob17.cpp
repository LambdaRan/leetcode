
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

/*
* Name: 17. Letter Combinations of a Phone Number
* Description: 
* Given a digit string, return all possible letter combinations that the number could represent.
* A mapping of digit to letters (just like on the telephone buttons) is given below.
*
*/
class Solution {
public:
    /*
    * Runtime:  3 ms
    * Your runtime beats  0.78% of cpp submissions. 
    */
    vector<string> letterCombinations(string digits);

    vector<string> base = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void recursive(string digits, string prefix, vector<string> &result);

    vector<string> letterCombinations2(string digits);
};

void printresult(vector<string> &result);

// void Solution::recursive(string digits, string prefix, vector<string> &result)
// {
//     size_t dsize = digits.size();

//     if (dsize == 0)
//     {
//         return;
//     }
//     else if (dsize == 1)
//     {
//         int digit = digits[0] - '0';
//         for (int i = 0; i < base[digit].size(); ++i)
//         {
//             result.push_back(prefix + base[digit][i]);
//         }            
//     }
//     else 
//     {
//         int digit = digits[0] - '0';
//         for (int i = 0; i <  base[digit].size(); ++i)
//         {
//             recursive(digits.substr(1), prefix+base[digit][i], result);
//         }
//     }
// }
// vector<string> Solution::letterCombinations(string digits) 
// {
//     vector<string> result;
//     if (!digits.empty())
//     {
//         recursive(digits, string(), result);
//     }
//     return result;
// }
vector<string> Solution::letterCombinations2(string digits) {
    char  phone[10][4]={ {' ',  '\0', '\0', '\0' }, //0
                         {'\0', '\0', '\0', '\0' }, //1
                         {'a',  'b',  'c',  '\0' }, //2
                         {'d',  'e',  'f',  '\0' }, //3
                         {'g',  'h',  'i',  '\0' }, //4
                         {'j',  'k',  'l',  '\0' }, //5
                         {'m',  'n',  'o',  '\0' }, //6
                         {'p',  'q',  'r',  's'  }, //7
                         {'t',  'u',  'v',  '\0' }, //8
                         {'w',  'x',  'y',  'z'  }  //9
                       };

    vector<string> result;
    if (digits.size()<=0){
        result.push_back("");
        return result;
    }
    for( int i=0; i<digits.size(); i++ ) {
        if (!isdigit(digits[i])) {
            vector<string> r;
            return r;
        } 
        int d = digits[i] - '0';
        if (result.size()<=0){
            for( int j=0; j<4 && phone[d][j]!='\0'; j++ ){
                string s;
                s += phone[d][j];
                result.push_back(s);
            }
            continue;
        }
        vector<string> r;
        for (int j=0; j<result.size(); j++){
            for( int k=0; k<4 && phone[d][k]!='\0'; k++ ){
                string s = result[j] + phone[d][k];
                //sort(s.begin(), s.end());
                r.push_back(s); 
            }
        }
        result = r;
    }
    //sort(result.begin(), result.end());

    return result; 
}

void printresult(vector<string> &result)
{
    std::cout << "[";
    for(auto var : result)
    {
        std::cout << var << ' ';
    }
    std::cout << "]";    
}
int main() 
{
    Solution s;    
    string example1 = "23";
    string expect1 = "[ad, ae, af, bd, be, bf, cd, ce, cf]";
    std::cout << "method 1: \n";
    std::cout << "letterCombinations(23): " << "\n";
    std::cout << "expect: " << '\n' << expect1 << '\n';
    vector<string> result1 = s.letterCombinations2(example1);
    printresult(result1); 
    std::cout << std::endl;
    return 0;
}