
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>
using namespace std;

int getResult(vector<int> nums)
{
    if (nums.size() == 0)
        return 0;
    int result = nums[0];
    int current = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
    {
        current = max(nums[i]+current, nums[i]);
        result = max(current, result);
    }
    return result;
}


int main()
{

    // cout << getResult({1,2,-1,3,4,5,-10}) << endl;
    // cout << getResult({-2,-3,-1,-5}) << endl;
    // cout << getResult({-1,-2,0,-3,-5}) << endl;
    
    int result = (1<<('t'-'a')) | (2 << ('e'-'a')) | (3 << ('n'-'a')) | (4 << ('c'-'a')) | (5 << ('e'-'a')) | (6 << ('n'-'a')) | (7 << ('t'-'a'));
    cout << result << endl;
    return 0;
}
