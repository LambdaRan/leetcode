
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iterator>

#include <cctype>

using namespace std;
/*
* Name: 492. Construct the Rectangle
* WebSite: https://leetcode.com/problems/construct-the-rectangle/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<int> constructRectangle(int area) {
        int a = sqrt(area);
        while (area % a) {
            a--;
        }
        return {area / a, a};
    }
    vector<int> constructRectangle(int area) {
        if (area <= 3) return vector<int>{area, 1};
        int areaSqrt = static_cast<int>(std::sqrt(area));
        if (areaSqrt * areaSqrt == area)
            return vector<int>{areaSqrt, areaSqrt};
        bool isPrimer = false; // 合数
        for (int i = 2; i <= areaSqrt; ++i) {
            if (area % i == 0) {
                isPrimer = true;
                break;
            }
        }
        if (!isPrimer)  return vector<int>{area, 1};
        // 如果是合数，然后 分解质因数
        vector<int> primers;
        std::cout << area << std::endl;
        for (int i = 2; i * i <= area; ++i) {
            while (area % i == 0) {
                area /= i;
                primers.emplace_back(i);
            }
        }
        if (area != 1) primers.emplace_back(area);


        std::copy(primers.begin(), primers.end(), std::ostream_iterator<int>(std::cout, " "));

        for (size_t i = 0, j = primers.size()-1; i < j; ) {
            // 找到 长和宽
            TODO    
        }
        int length = primers.back();
        int width = std::accumulate(primers.begin(), std::prev(primers.end()), 
                                    1, std::multiplies<int>());
        if (length < width)
            std::swap(length, width);
        return vector<int>{length, width};
    }  
};

int main() 
{
    Solution s; 
    int area = 0;
    while (std::cin >> area) {
        if (area < 0 || area > 10000000)
            continue;
        auto ret = s.constructRectangle(area);
        std::cout << "L:" << ret[0] << " W:" << ret[1] << std::endl;
    }

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}                