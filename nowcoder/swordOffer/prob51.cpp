
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 构建乘积数组
* Description: 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
* 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*
*/
class Solution {
public:
//B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
//从左到右算 B[i]=A[0]*A[1]*...*A[i-1]
//从右到左算B[i]*=A[i+1]*...*A[n-1]
    vector<int> multiply(const vector<int>& A) {

        int n = A.size();
        vector<int> b(n);
        int ret=1;
        //计算下三角连乘
        for(int i=0; i<n; ret *= A[i++])
        {
            b[i] = ret;
        }
        ret = 1;
        //计算上三角
        for(int i = n-1; i >= 0; ret *= A[i--])
        {
            b[i] *= ret;
        }

        return b;    
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
