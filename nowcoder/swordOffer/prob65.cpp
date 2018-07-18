
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <stack>

#include <string.h>

using namespace std;

/*
* Name: 矩阵中的路径
* Description: 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
* 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
* 如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
* 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
* 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*
*/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (matrix == NULL || str == NULL) return false;
        int rowsIndex = 0;
        int closIndex = 0;
        int strIndex = 0;
        int strSize = static_cast<int>(::strlen(str));
        std::stack<std::pair<int, int>> matchPoint;
        std::vector<std::vector<int>> isVist(rows, std::vector<int>(cols, 0));
        while (true)
        {
            for (int i = rowsIndex; i < rows; ++i)
            {
                for (int j = closIndex; j < cols; ++j)
                {
                    if (matrix[i][j] == str[strIndex++])
                    {
                        rowsIndex = i;
                        closIndex = j;
                        matchPoint.push(std::make_pair(i,j));
                        isVist[i][j] = 1;
                        break;
                    }
                }
            }
            if (matchPoint.empty()) return false;

            while (!matchPoint.empty())
            {
                if (strIndex == strSize) return true;

                if (rowsIndex-1 >= 0) // 上
                {
                    if (!isVist[rowsIndex-1][closIndex] &&
                        matrix[rowsIndex-1][closIndex] == str[strIndex])
                    {
                        --rowsIndex;
                        ++strIndex;
                        matchPoint.push(std::make_pair(rowsIndex, closIndex));
                        isVist[rowsIndex][closIndex] = 1;
                        continue;
                    }
                    isVist[rowsIndex-1][closIndex] = 1;
                }

                if (closIndex+1 < cols) // 右
                {
                    if (!isVist[rowsIndex][closIndex+1] &&
                        matrix[rowsIndex][closIndex+1] == str[strIndex])
                    {
                        ++closIndex;
                        ++strIndex;
                        matchPoint.push(std::make_pair(rowsIndex, closIndex));                       
                        isVist[rowsIndex][closIndex] = 1;
                        continue;                        
                    }
                    isVist[rowsIndex][closIndex+1] = 1;
                }

                if (rowsIndex+1 < rows) // 下
                {
                    if (!isVist[rowsIndex+1][closIndex] &&
                        matrix[rowsIndex+1][closIndex] == str[strIndex])
                    {
                        ++rowsIndex;
                        ++strIndex;
                        matchPoint.push(std::make_pair(rowsIndex, closIndex));                       
                        isVist[rowsIndex][closIndex] = 1;
                        continue;                         
                    }
                    isVist[rowsIndex+1][closIndex] = 1;
                }

                if (closIndex-1 >= 0)
                {
                    if (!isVist[rowsIndex][closIndex-1] && 
                        matrix[rowsIndex][closIndex-1] == str[strIndex])
                    {
                        --closIndex;
                        ++strIndex;
                        matchPoint.push(std::make_pair(rowsIndex, closIndex));                       
                        isVist[rowsIndex][closIndex] = 1;
                        continue;  
                    }
                    isVist[rowsIndex][closIndex-1] = 1;
                }

                // 回溯
                std::pair<int, int> prePoint = matchPoint.top();
                matchPoint.pop();
                rowsIndex = prePoint.first;
                closIndex = prePoint.second;
                --strSize;
            }
            isVist.clear();
        }    
    }

};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
