
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>


using namespace std;

int maxSubArray(vector<int>& nums) 
{
    int sum = -100000, temp = 0;
    for(auto const &num : nums)
    {
        temp = max(temp + num, num);
        sum = max(temp, sum);
    }
    
    return sum;
}

int maxSum3(vector<int>&vec, const int start, const int end, int &left, int &right)
{
    if(start == end)
    {
        left = start;
        right = left;
        return vec[start];
    }
    int middle = start + ((end - start)>>1);
    int lleft, lright, rleft, rright;
    int maxLeft = maxSum3(vec, start, middle, lleft, lright);//左半部分最大和
    int maxRight = maxSum3(vec, middle+1, end, rleft, rright);//右半部分最大和
    int maxLeftBoeder = vec[middle], maxRightBorder = vec[middle+1], mleft = middle, mright = middle+1;
    int tmp = vec[middle];
    for(int i = middle-1; i >= start; i--)
    {
        tmp += vec[i];
        if(tmp > maxLeftBoeder)
        {
            maxLeftBoeder = tmp;
            mleft = i;
        }
    }
    tmp = vec[middle+1];
    for(int i = middle+2; i <= end; i++)
    {
        tmp += vec[i];
        if(tmp > maxRightBorder)
        {
            maxRightBorder = tmp;
            mright = i;
        }
    }
    int res = max(max(maxLeft, maxRight), maxLeftBoeder+maxRightBorder);
    if(res == maxLeft)
    {
        left = lleft;
        right = lright;
    }
    else if(res == maxLeftBoeder+maxRightBorder)
    {
        left = mleft;
        right = mright;
    }
    else
    {
        left = rleft;
        right = rright;
    }
    return res;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ivec(n);
    for(int i = 0; i < n; ++i)
        cin >> ivec[i];
    
    if (m == 1)
        cout << maxSubArray(ivec) << endl;
    int sum = 0;
    for (int i = 0; i < m; ++i)
    {
        int left, right;
        int ret = maxSum3(ivec, 0, ivec.size(); left, right);
        if (ret > 0)
        {
            sum += ret;
            for (int j = left; j < right; ++j)
            {
                ivec[j] = -1;
            }
        }
        else  
            break;
    }
    cout << sum << endl;
    return 0;
}
