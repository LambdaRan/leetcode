
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


using namespace std;

/*
* Name: 顺时针打印矩阵
* Description: 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
* 例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
* 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {

        //if (matrix.empty()) return vector<int>();
        
        int rowsFirst = 0;
        int rowsLast = static_cast<int>(matrix.size() - 1);
        int columnsFirst = 0;
        int columnsLast = static_cast<int>(matrix[0].size() - 1);
        std::cout << "matrix.siz: " << matrix.size() 
                    << "rowsLast: " << rowsLast 
                    << "columnsLast: " << columnsLast << "\n";
        vector<int> result;
        while (rowsLast > rowsFirst)
        {
            // 打印第一行行
            for (int i = columnsFirst; i <= columnsLast; ++i)
            {
                result.push_back(matrix[rowsFirst][i]);
            }
            ++rowsFirst;

            // 打印最右一列
            for (int i = rowsFirst; i <= rowsLast; ++i)
            {
                result.push_back(matrix[i][columnsLast]);
            }
            --columnsLast;

            // 打印最下面一行
            for (int i = columnsLast; i >= columnsFirst; --i)
            {
                result.push_back(matrix[rowsLast][i]);
            }
            --rowsLast;
            // 打印最左一列
            for (int i = rowsLast; i >= rowsFirst; --i)
            {
                result.push_back(matrix[i][columnsFirst]);
            }
            ++columnsFirst;
        }
        if (rowsFirst == rowsLast)
        {
            for (int i = columnsFirst; i <= columnsLast; ++i)
            {
                result.push_back(matrix[rowsFirst][i]);
            }
        }

        return result;
    }
};

int main() 
{
    Solution s;
    vector<vector<int> > testVec = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
您的代码已保存
答案错误:您提交的程序没有通过所有的测试用例
case通过率为36.36%

测试用例:
[[1],[2],[3],[4],[5]]

对应输出应该为:

[1,2,3,4,5]

你的输出为:

[1,2,3,4,5,4,3,2,0,0,10]
    vector<int> result = s.printMatrix(testVec);
    std::cout << "result.size: " << result.size() << "\n";
    std::cout << "expect:\n 1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10\n";
    std::cout << "result:\n";
    
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    return 0;
}