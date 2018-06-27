
#include <iostream>
#include <algorithm>

#include <vector>
#include <iterator>

using namespace std;

/*
* Name: 最小的K个数
* Description: 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution_Algorithm(vector<int> input, int k) 
    {
        int size = static_cast<int>(input.size());
        if (size < 0 || k < 0 || size < k) return vector<int>();
        std::partial_sort(input.begin(), input.begin()+k, input.end());
        return vector<int>(input.begin(), input.begin()+k);
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
    {
        int size = static_cast<int>(input.size());
        if (size < 0 || k < 0 || size < k) return vector<int>();
        
        vector<int>::iterator first = input.begin();
        vector<int>::iterator last = input.end();
        while (first < last)
        {
            int pivot = *std::next(input.begin(), std::distance(first, last)/2);
            std::cout << "pivot: " << pivot << "\n";
            vector<int>::iterator middle = std::partition(input.begin(), input.end(), 
                                            [pivot](const int em){ return em < pivot; });
            int dist = static_cast<int>(std::distance(input.begin(), middle));
            std::cout << "dist: " << dist << "\n";
            if (dist == k)
                break;
            else if (dist < k)
                first = std::next(input.begin(), dist+1);
            else  
                last = std::next(input.begin(), dist-1);
            std::cout << "first: " << *first << "mid: " << *middle << "\n";

            break;
        }
        return vector<int>(input.begin(), std::next(input.begin(), k));
    }    
};

int main() 
{
    Solution s;
    // vector<int> vec = {4,5,1,6,2,7,3,8};
    // vector<int> result = s.GetLeastNumbers_Solution(vec, 4);
    // std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";

    // vector<int> vec1 = {4};
    // result = s.GetLeastNumbers_Solution(vec1, 1);
    // std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";

    // vector<int> vec2 = {4,5};
    // result = s.GetLeastNumbers_Solution(vec2, 2);
    // std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";

    vector<int> vec3 = {4,5,1,2,3,2,1,2,2,2};
    vector<int> result = s.GetLeastNumbers_Solution(vec3, 5);
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    std::cout << std::endl;
    return 0;
}
