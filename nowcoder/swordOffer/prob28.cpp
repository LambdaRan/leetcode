
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
* Name: 数组中出现次数超过一半的数字
* Description: 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
* 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，
* 因此输出2。如果不存在则输出0。
*
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
        int half =static_cast<int>(numbers.size()/2);
        map<int, int> numberCountMap;
        int count = 0;
        for (auto &v : numbers)
        {
            numberCountMap[v]++;
        }

        for (map<int, int>::const_iterator it = numberCountMap.begin();
            it != numberCountMap.end(); ++it)
        {
            if (it->second > half)
                return it->first;
            count += it->second;
            if (count > half)
                return 0;
        }
        return 0;        
    }

    // int MoreThanHalfNum_Solution2(vector<int> numbers) {
    //     int n = numbers.size();
    //     if (n == 0) return 0;

    //     int num = numbers[0], count = 1;
    //     for (int i = 1; i < n; i++) {
    //         if (numbers[i] == num) count++;
    //         else count--;
    //         if (count == 0) {
    //             num = numbers[i];
    //             count = 1;
    //         }
    //     }
    //     // Verifying
    //     count = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (numbers[i] == num) count++;
    //     }
    //     if (count * 2 > n) return num;
    //     return 0;
    // }
};

int main() 
{
    Solution s;
    vector<int> vec1 = {1};
    vector<int> vec2 = {1,2};
    vector<int> vec3 = {1,3,3};
    vector<int> vec4 = {1,2,3,2,2,2,5,4,2};

    std::cout << "method 1: \n";
    std::cout << "1 --> " << s.MoreThanHalfNum_Solution(vec1) << "\n";
    std::cout << "0 --> " << s.MoreThanHalfNum_Solution(vec2) << "\n";
    std::cout << "3 --> " << s.MoreThanHalfNum_Solution(vec3) << "\n";
    std::cout << "2 --> " << s.MoreThanHalfNum_Solution(vec4) << "\n";

    std::cout << std::endl;
    return 0;
}
