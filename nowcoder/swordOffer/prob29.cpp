
#include <iostream>
#include <algorithm>

#include <vector>
#include <iterator>
#include <set>

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

        typedef multiset<int, greater<int>> intSet;

        intSet ekSet(input.begin(), next(input.begin(), k));
        for (vector<int>::iterator it = std::next(input.begin(), k);
                it != input.end(); ++it)
        {
            if (*it < *ekSet.begin())
            {
                ekSet.erase(ekSet.begin());
                ekSet.insert(*it);
            }
        }

        return vector<int>(ekSet.begin(), ekSet.end());        
    }
    vector<int> GetLeastNumbers_Solution_heap_error(vector<int> input, int k) 
    {
        int size = static_cast<int>(input.size());
        if (size < 0 || k < 0 || size < k) return vector<int>();
        
        vector<int> vecK(input.begin(), std::next(input.begin(), k));
        std::make_heap(vecK.begin(), vecK.end());
        std::pop_heap(vecK.begin(), vecK.end());
        int maxK = vecK.back();
        vecK.pop_back();
        for (vector<int>::iterator it = std::next(input.begin(), k);
                it != input.end(); ++it)
        {
            if (*it < maxK)
            {
                vecK.push_back(*it);
                std::push_heap(vecK.begin(), vecK.end());
                std::pop_heap(vecK.begin(), vecK.end());
                maxK = vecK.back();
                vecK.pop_back();
            }
        }
        vecK.push_back(maxK);
        return vecK;
    }    
};

int main() 
{
    Solution s;
    vector<int> vec = {4,5,1,6,2,7,3,8};
    vector<int> result = s.GetLeastNumbers_Solution(vec, 4);
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    vector<int> vec1 = {4};
    result = s.GetLeastNumbers_Solution(vec1, 1);
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    vector<int> vec2 = {4,5};
    result = s.GetLeastNumbers_Solution(vec2, 2);
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    vector<int> vec3 = {4,5,1,2,3,2,1,2,2,2};
    result = s.GetLeastNumbers_Solution(vec3, 5);
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    std::cout << std::endl;
    return 0;
}
