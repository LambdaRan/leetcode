
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// 开始的时候题意理解错误；
// 题意： 格式为 Z 字形顺序显示输入的字符，然后按行输出
/*
* 1        7        13
* 2     6  8     12
* 3  5     9  11
* 4        10
*/
string convert(string s, int numRows) {

    if (numRows > s.size() || numRows <= 1)
        return s;

    vector<string> mlines(numRows);
    int row = 0;
    int step = 1;

    for (int i = 0; i < s.size(); ++i) {
        if (row == numRows - 1)
            step = -1;
        if (row == 0)
            step = 1;
        
        mlines[row] += s[i];
        row += step;
    }

    string result;
    for (int i = 0; i < numRows; ++i)
        result += mlines[i];
    
    return result;
}

string convert2(string s, int numRows) {
    if (numRows > s.size() || numRows <= 1)
        return s;
    
    vector<string> mlines(numRows);
    int mindex = 0;
    while (mindex < s.size()) {

        for (int row = 0; row < numRows && mindex < s.size(); ++row)
            mlines[row] += s[mindex++];
        for (int row = numRows - 2; row > 0 && mindex < s.size(); --row)
            mlines[row] += s[mindex++];        
    }

    string result;
    for (int i = 0; i < numRows; ++i)
        result += mlines[i];  

    return result;
}
int main()
{
    string ret = convert2("PAYPALISHIRING", 3);

    std::cout << "test result: " << ret << std::endl;
    return 0;
}