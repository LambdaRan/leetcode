
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int minPatches(vector<int>& nums, int n) 
    {
        //long twoMultiple = 1;
        long sum = 1;
        int patch = 0;
        int numIdx = 0;

        while (sum < n )
        {
            if (numIdx < nums.size() && sum >= nums[numIdx])
            {
                sum += nums[numIdx];
                ++numIdx;
            }
            else  
            {
                //sum += sum+1 < twoMultiple ? sum+1 : twoMultiple;
                sum += sum;
                ++patch;
            }
            //twoMultiple = 2 * twoMultiple;
        }
        return patch;
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    vector<int> number = {1,2,31,33};
    cout << s.minPatches(number, 2147483647) << endl;;

    vector<int> number1 = {10,30,36,42,50,76,87,88,91,92};
    cout << s.minPatches(number1, 54) << endl;

    std::cout << std::endl;
    return 0;
}