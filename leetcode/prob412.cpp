
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
/*
* Name: 412. Fizz Buzz
* Website: https://leetcode.com/problems/fizz-buzz/description/
* Description: 
*
*/
class Solution
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        if (n < 1) return result;
        bool isThree = false;
        bool isFive = false;
        for (int i = 1; i <= n; ++i)
        {
            isThree = i % 3 == 0;
            isFive = i % 5 == 0;
            if (isThree && isFive)
                result.emplace_back("FizzBuzz");
            else 
            {
                if (isThree)
                    result.emplace_back("Fizz");
                else if (isFive)
                    result.emplace_back("Buzz");
                else
                    result.emplace_back(to_string(i));
            }    
        }
        return result;
        // 方法二：
        // vector<string> result(n,"");
        // for(int i=2;i<n;i+=3)
        //     result[i].append("Fizz");
        // for(int i=4;i<n;i+=5)
        //     result[i].append("Buzz");
        // for(int i=0;i<n;i++)
        // {
        //     if(result[i].length()==0)
        //         result[i].append(std::to_string(i+1));
        // }
        // return result;
        // 方法三：
        // Condition 1: 15 % 3 == 0 , num_ans_str = "Fizz"
        // Condition 2: 15 % 5 == 0 , num_ans_str += "Buzz"
        // => num_ans_str = "FizzBuzz"
        // 方法四： 使用map
    }
};

int main()
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}