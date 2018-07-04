
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 数组中的逆序对
* Description: 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
* 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
* 输入描述:
* 题目保证输入的数组中没有的相同的数字
* 
* 数据范围：
* 	对于%50的数据,size<=10^4
* 	对于%75的数据,size<=10^5 
* 	对于%100的数据,size<=2*10^5
* 
* 示例1
* 输入 1,2,3,4,5,6,7,0
* 输出 7
*
*/
class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.empty()) return 0;
        vector<int> dummy(data);

        size_t count = _inversePairsMerge(data, dummy, 0, static_cast<int>(data.size()-1));
        return static_cast<int>(count % 1000000007);
    }
private: 
    size_t _inversePairsMerge(vector<int> &data, vector<int> &dummy, int start, int end)
    {
        if(start == end)
        {
            dummy[start] = data[start];
            return 0;
        }  

        int length = (end - start) / 2;
        size_t leftCount = _inversePairsMerge(dummy, data, start, start+length);
        size_t rightCount = _inversePairsMerge(dummy, data, start+length+1, end);

        int i = start + length;
        int j = end;
        int indexdummy = end;
        size_t curCount = 0;
        while ( i >= start && j >= start+length+1)
        {
            if(data[i] > data[j]) // 左边最后元素大于右边最后元素
            {
                dummy[indexdummy--] = data[i--];
                curCount += j - start - length;
            }
            else  
            {
                dummy[indexdummy--] = data[j--];
            }
        }
        for(; i >= start; --i)
            dummy[indexdummy--] = data[i];

        for(; j >= start+length+1; --j)
            dummy[indexdummy--] = data[j];

        return leftCount + rightCount + curCount;       
    }
};

int main() 
{
    Solution s;

    vector<int> vec = {1,2,3,4,5,6,7,0};
    std::cout << "method 1: \n";
    std::cout << "count: 7 --> " << s.InversePairs(vec);
    std::cout << std::endl;
    return 0;
}
