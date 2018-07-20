

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
class Solution2
{
  public:
    bool hasPath(const char *matrix, int rows, int cols, const char *str)
    {
        if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
            return false;
        bool *flag = new bool[rows * cols];
        memset(flag, false, rows * cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matchPoint(matrix, rows, cols, i, j, str, 0, flag))
                {
                    return true;
                }
            }
        }
        delete[] flag;
        return false;
    }
    /*参数说明*/
    bool matchPoint(const char *matrix, int rows, int cols, 
                int i, int j, const char *str, int k, bool *flag)
    {
        //因为是一维数组存放二维的值，index值就是相当于二维数组的（i，j）在一维数组的下标
        int index = i * cols + j;
        //flag[index]==true,说明被访问过了，那么也返回true;
        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == true)
            return false;
        //字符串已经查找结束，说明找到该路径了
        if (str[k + 1] == '\0')
            return true;
        //向四个方向进行递归查找,向左，向右，向上，向下查找
        flag[index] = true; //标记访问过
        if (matchPoint(matrix, rows, cols, i - 1, j, str, k + 1, flag)
              || matchPoint(matrix, rows, cols, i + 1, j, str, k + 1, flag)
              || matchPoint(matrix, rows, cols, i, j - 1, str, k + 1, flag)
              || matchPoint(matrix, rows, cols, i, j + 1, str, k + 1, flag))
        {
            return true;
        }
        flag[index] = false;
        return false;
    }
};
class Solution
{
  public:
    bool hasPath(const char *matrix, int rows, int cols, const char *str)
    {
        if (matrix == NULL || str == NULL)
            return false;
        int rowsIndex = 0;
        int closIndex = 0;
        int strIndex = 0;
        int strSize = static_cast<int>(::strlen(str));
        int matrixSize = static_cast<int>(::strlen(matrix));
        if (strSize > matrixSize)
            return false;

        //std::stack<std::pair<int, int>> matchPoint;

        for (int i = rowsIndex; i < rows; ++i)
        {
            for (int j = closIndex; j < cols; ++j)
            {
                if (matrix[i * cols + j] == str[strIndex])
                {
                    std::vector<std::vector<int>> isVist(rows, std::vector<int>(cols, 0));
                    std::stack<std::pair<int, int>> matchPoint;
                    //std::cout << "find: " << matrix[i * cols + j] << " "
                    //    << str[strIndex] << " " << i << " " << j << std::endl;
                    rowsIndex = i;
                    closIndex = j;
                    matchPoint.push(std::make_pair(i, j));
                    isVist[i][j] = 1;
                    ++strIndex;
                    while (!matchPoint.empty())
                    {
                        //std::cout << "strIndex: " << strIndex << " strSize: " << strSize << std::endl;
                        if (strIndex == strSize)
                            return true;
                        if (str[strIndex] == '\0') return true;
                        if (rowsIndex - 1 >= 0) // 上
                        {
                            if (!isVist[rowsIndex - 1][closIndex] &&
                                matrix[(rowsIndex - 1) * cols + closIndex] == str[strIndex])
                            {
                                //std::cout << "1find: " << matrix[(rowsIndex-1)*cols+closIndex] << " "
                                //    << str[strIndex] << " " << (rowsIndex-1) << " " << closIndex << std::endl;
                                --rowsIndex;
                                ++strIndex;
                                matchPoint.push(std::make_pair(rowsIndex, closIndex));
                                isVist[rowsIndex][closIndex] = 1;
                                continue;
                            }
                            //isVist[rowsIndex-1][closIndex] = 1;
                        }

                        if (closIndex + 1 < cols) // 右
                        {
                            if (!isVist[rowsIndex][closIndex + 1] &&
                                matrix[rowsIndex * cols + closIndex + 1] == str[strIndex])
                            {
                                //std::cout << "2find: " << matrix[rowsIndex*cols+closIndex+1] << " "
                                //    << str[strIndex] << " " << rowsIndex << " " << (closIndex+1) << std::endl;
                                ++closIndex;
                                ++strIndex;
                                matchPoint.push(std::make_pair(rowsIndex, closIndex));
                                isVist[rowsIndex][closIndex] = 1;
                                continue;
                            }
                            //isVist[rowsIndex][closIndex+1] = 1;
                        }

                        if (rowsIndex + 1 < rows) // 下
                        {
                            if (!isVist[rowsIndex + 1][closIndex] &&
                                matrix[(rowsIndex + 1) * cols + closIndex] == str[strIndex])
                            {
                                //std::cout << "3find: " << matrix[(rowsIndex+1)*cols+closIndex] << " "
                                //    << str[strIndex] << " " << (rowsIndex+1) << " " << closIndex << std::endl;
                                ++rowsIndex;
                                ++strIndex;
                                matchPoint.push(std::make_pair(rowsIndex, closIndex));
                                isVist[rowsIndex][closIndex] = 1;
                                continue;
                            }
                            //isVist[rowsIndex+1][closIndex] = 1;
                        }

                        if (closIndex - 1 >= 0)
                        {
                            if (!isVist[rowsIndex][closIndex - 1] &&
                                matrix[rowsIndex * cols + closIndex - 1] == str[strIndex])
                            {
                                //std::cout << "4find: " << matrix[rowsIndex*cols+closIndex-1] << " "
                                //    << str[strIndex] << " " << rowsIndex << " " << (closIndex-1)<< std::endl;
                                --closIndex;
                                ++strIndex;
                                matchPoint.push(std::make_pair(rowsIndex, closIndex));
                                isVist[rowsIndex][closIndex] = 1;
                                continue;
                            }
                            //isVist[rowsIndex][closIndex-1] = 1;
                        }

                        // 回溯
                        matchPoint.pop();
                        if (matchPoint.empty()) break;
                        std::pair<int, int> prePoint = matchPoint.top();
                        rowsIndex = prePoint.first;
                        closIndex = prePoint.second;
                        --strIndex;
                        //std::cout << "pre_rowsIndex:" << rowsIndex << " pre_colsIndex:" << closIndex << std::endl;
                    }
                     // 弄明白clear()原理
                    //isVist.clear();
                    strIndex = 0;
                }
            }
        }
        return false;
    }
};
std::string boolToString(bool input)
{
    return input ? "True" : "False";
}
int main()
{
    Solution s;
    //char* matrix = ;
    //char* str = ;
    std::cout << "method 1: \n";
    std::cout << "true  " << boolToString(s.hasPath("ABCESFCSADEE", 3, 4, "SEE")) << "\n";
    std::cout << std::endl;
    std::cout << "false  " << boolToString(s.hasPath("ABCESFCSADEE", 3, 4, "ABCB")) << "\n";
    std::cout << std::endl;
    std::cout << "false  " << boolToString(s.hasPath("ABCESFCSADEE", 3, 4, "")) << "\n";
    std::cout << std::endl;
    std::cout << "true  " << boolToString(s.hasPath("ABCESFCSADEE", 3, 4, "SFDEES")) << "\n";
    std::cout << std::endl;
    std::cout << "true  " << boolToString(s.hasPath("ABCESFCSADEE", 3, 4, "C")) << "\n";
    std::cout << std::endl;
    std::cout << "true  " << boolToString(s.hasPath("ABCESFCSADEE", 3, 4, "ASADFCEES")) << "\n";
    std::cout << std::endl;
    std::cout << "false  " << boolToString(s.hasPath("A", 1, 1, "AA")) << "\n";
    std::cout << std::endl;
    std::cout << "false  " << boolToString(s.hasPath("ABCD", 1, 4, "ABCDE")) << "\n";
    std::cout << std::endl;
    return 0;
}
