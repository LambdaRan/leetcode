
#include <iostream>
#include <algorithm>
#include <iterator>


using namespace std;

/*
* Name: 调整数组顺序使奇数位于偶数前面
* Description: 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
* 所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) 
    {
        size_t arraySize = array.size();
        if (arraySize <= 1) return;

        vector<int> tmp(arraySize);
        size_t oddIndex = 0;
        size_t evenIdex = arraySize - 1;
        for (size_t i = 0; i < arraySize; ++i)
        {
            if (array[i]  & 1 != 0)
                tmp[oddIndex++] = array[i];
            else  
                tmp[evenIdex--] = array[i];
        }
        //cout << "oddIndex: " << oddIndex << " evenIndex: " << evenIdex << "\n";
        for (size_t i = 0; i < oddIndex; ++i)
        {
            array[i] = tmp[i];
        }
        for (size_t i = arraySize-1; i > evenIdex; --i)
        {
            array[oddIndex++] = tmp[i];
        }        
    }

    void reOrderArray1(vector<int> &array) 
    {
        stable_partition(array.begin(), array.end(), [](int n){ return n & 1 != 0; });
    }
};

int main() 
{
    Solution s;
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    std::cout << "method 1: \n";

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));

    s.reOrderArray(vec);
    cout << "\n";
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    std::cout << std::endl;
    return 0;
}