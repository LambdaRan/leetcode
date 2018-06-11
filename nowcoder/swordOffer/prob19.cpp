
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
        
        if (matrix.size() <= 1) return matrix[0];
        
        int rowsFirst = 0;
        int rowsLast = static_cast<int>(matrix.size() - 1);
        int columnsFirst = 0;
        int columnsLast = static_cast<int>(matrix[0].size() - 1);

        vector<int> result;
        while (rowsFirst <= rowsLast && columnsFirst <= columnsLast)
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
            if (rowsFirst <= rowsLast)
            for (int i = columnsLast; i >= columnsFirst; --i)
            {
                result.push_back(matrix[rowsLast][i]);
            }
            --rowsLast;
            
            // 打印最左一列
            if (columnsFirst <= columnsLast)
            for (int i = rowsLast; i >= rowsFirst; --i)
            {
                result.push_back(matrix[i][columnsFirst]);
            }
            ++columnsFirst;
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
    vector<vector<int> > testVec1 = {
        {1},
        {2},
        {3},
        {4},
        {5}
    };    
    vector<int> result = s.printMatrix(testVec);
    std::cout << "expect:\n 1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10\n";
    std::cout << "result:\n";
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << "\n";

    result = s.printMatrix(testVec1);
    std::cout << "expect:\n 1,2,3,4,5\n";
    std::cout << "result:\n";
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << "\n";

    std::cout << std::endl;

    return 0;
}