

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getVale(vector<int>& vec, 
            size_t vecIdex,
            size_t prevIdex,
            int value,
            int& max,
            bool selectFirst)
{
    // 最后一个商店
    if (vecIdex == vec.size()-1)
    {
        if (vec[vecIdex] > vec[prevIdex] && // 当前商店大于以前所选商店
            vecIdex - prevIdex > 1 && // 相邻商店不能选
            !selectFirst)   // 首尾不能选
        {
            cout << "here 1" << endl;
            int sum = value + vec[vecIdex];
            max = max > sum ? max : sum;
        }
    }
    else  
    {
        for (size_t i = vecIdex; i < vec.size(); ++i)
        {
            cout << "here 2" << endl;
            if (!selectFirst && prevIdex == 0) 
            {
                cout << "here 3" << endl;
                if (i - prevIdex > 1) // 相邻商店不能选
                {
                    // 不选择这个商店
                    getVale(vec, i, prevIdex, value, max, selectFirst);
                    // 选择这个商店
                    int curSum = value+vec[i];
                    max = max > curSum ? max : curSum;
                    getVale(vec, i, i, curSum, max, selectFirst);
                }
            }
            else  
            {
                cout << "here 4" << endl;
                if (vec[i] > vec[prevIdex] && // 当前商店大于以前所选商店
                    i - prevIdex > 1) // 相邻商店不能选
                {
                    // 不选择这个商店
                    getVale(vec, i, prevIdex, value, max, selectFirst);
                    // 选择这个商店
                    int curSum = value+vec[i];
                    max = max > curSum ? max : curSum;
                    getVale(vec, i, i, curSum, max, selectFirst);
                }                
            }
        }
    }
}
// 6 3 8 6 9 7 6
int main()
{
    int N = 0;
    cin >> N;

    vector<int> ai;
    int curNUM = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> curNUM;
        ai.push_back(curNUM);
    }

    if (N == 1)
    {
        cout << ai[0] << endl;
        return 0;
    }
        
    if (N == 2)
    {
        cout<< std::max(ai[0], ai[1]) << endl;
        return 0;
    }

    cout << " start " << endl;
    int max = 0;
    // 不选择第一个商店
    getVale(ai, 1, 0, 0, max, false);

    // 选择第一个商店
    max = ai[0];
    getVale(ai, 1, 0, ai[0], max, true);

    cout << max << endl;

    return 0;
}