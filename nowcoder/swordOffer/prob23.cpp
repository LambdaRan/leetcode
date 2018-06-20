
#include <iostream>
#include <algorithm>

using namespace std;

/*
* Name: 二叉搜索树的后序遍历序列
* Description: 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
* 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*
*/

// 思想：
// BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），
// 如果去掉最后一个元素的序列为T，那么T满足：T可以分成两段，前一段（左子树）小于x，
// 后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。完美的递归定义 : )
class Solution
{
  public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        int size = static_cast<int>(sequence.size());
        if (0 == size)
            return false;
        while (--size)
        {
            int i = 0;
            while (sequence[i++] < sequence[size]);
            while (sequence[i++] > sequence[size]);

            if (i < size)
                return false;
        }
        return true;
    }
    bool VerifySquenceOfBST1(vector<int> &sequence)
    {
        if (sequence.size() <= 0)
            return false;

        return checkSubSequeue(sequence, 0, static_cast<int>(sequence.size() - 1));
    }

  private:
    bool checkSubSequeue(vector<int> &sequeue, int left, int right)
    {
        if (left >= right)
            return true;

        int i = right;
        while (left <= right && sequeue[i - 1] > sequeue[right])
            --i;
        for (int j = i - 1; j >= 0; --j)
        {
            if (sequeue[j] > sequeue[right])
                return false;
        }
        return checkSubSequeue(sequeue, left, i - 1) &&
               checkSubSequeue(sequeue, i, right - 1);
    }
};
std::string boolToString(bool input)
{
    return input ? "True" : "False";
}
int main()
{
    Solution s;
    vector<int> testVec = {5, 7, 6, 9, 11, 10, 8};

    std::cout << "test1: true --> " << boolToString(s.VerifySquenceOfBST(testVec));
    std::cout << std::endl;
    return 0;
}