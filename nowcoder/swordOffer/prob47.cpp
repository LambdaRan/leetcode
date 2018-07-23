
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 求1+2+3+...+n
* Description: 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等
* 关键字及条件判断语句（A?B:C）。
*
*/
class Solution {
public:
    // 这里采用递归调用的思想，并借用&&的短路特性来求解 
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));
        return ans;        
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
