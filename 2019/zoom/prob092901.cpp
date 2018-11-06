
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
// #include <sstream>
// #include <cctype>
//#include <stdio.h>
#include <map>
using namespace std;

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
        if (it->second >= half)
            return it->first;
        count += it->second;
        if (count >= half)
            return 0;
    }
    return 0;        
}
int main()
{
    int n = 0;
    cin >> n;
    int half = n/2;
    map<int, int> numberCountMap;
    int count = 0;
    //vector<int> vec(n);
    //for (int i = 0; i < n; ++i)
    //    cin >> vec[i];
    
    int result = MoreThanHalfNum_Solution(vec);
    cout << result << endl;
    return 0;
}
void dfs(vector<int>& nums, int i, int cursum) 
{    
    if (i == nums.size()) 
    {        
        ans = min(ans, abs(sum-2*cursum));
        return;    
    }    
    dfs(i+1, cursum + nums[i]);   
    dfs(i+1, cursum);
}