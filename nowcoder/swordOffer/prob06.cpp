
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* Name: 旋转数组的最小数字
* Description: 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
* 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
* 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
* NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*
*/

// 输入的是非递减数列的一个旋转，求旋转以后数组中的最小值。
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) return 0;
        
        int left = 0;
        int right = static_cast<int>(rotateArray.size())-1;
        int mid = 0;
        while (rotateArray[left] >= rotateArray[right])
        {
            if (right - left == 1)
            {
                mid = right;
                break;
            }
            mid = (left + right) / 2;
            // rotateArray[left] rotateArray[right] rotateArray[mid]三者相等
            // 无法确定中间元素是属于前面还是后面的递增子数组
            // 只能顺序查找
            if(rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid])
            {
                return *min_element(rotateArray.begin()+left, rotateArray.begin()+right);
            }
            // 中间元素位于前面的递增子数组
            // 此时最小元素位于中间元素的后面
            if(rotateArray[mid] >= rotateArray[left])
            {
                left = mid;
            }
            // 中间元素位于后面的递增子数组
            // 此时最小元素位于中间元素的前面
            else
            {
                right = mid;
            }
        }
        return rotateArray[mid];      
    }
};

int main() 
{
    Solution s;
    vector<int> v1 = {3,4,5,1,2};
    std::cout << "method 1: \n";
    cout << s.minNumberInRotateArray(v1);
    std::cout << std::endl;
    return 0;
}