
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
* 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
* 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 
*
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {

        if (array.size() == 0) return false;

        int rowSize = static_cast<int>(array.size()); 
        int columnSize = static_cast<int>(array[0].size());
        for (int i = 0, j = columnSize-1; i < rowSize && j >= 0; )
        {
            if (target == array[i][j])
            {    
                return true;
            }
            else if (target < array[i][j])
            {
                --j;
            }
            else  
            {
                ++i;
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
    vector<vector<int>> testVector= {
        {1, 2, 3},
        {4, 5}
    };
    std::cout << "method 1: \n";
    std::cout <<  "function(2): true <------> " << boolToString(s.Find(2, testVector)) << "\n";
    std::cout <<  "function(7): false <------> " << boolToString(s.Find(7, testVector)) << "\n";
    //std::cout <<  "function(): true <------> " << boolToString(s.Find(2, testVector)) << "\n";
    //std::cout <<  "function(): true <------> " << boolToString(s.Find(2, testVector)) << "\n";
    std::cout << std::endl;
    return 0;
}