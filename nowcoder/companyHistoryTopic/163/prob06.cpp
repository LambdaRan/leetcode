#include <iostream>
#include <algorithm>

using namespace std;
const int kMax = 51;

int main()
{
    int nCity = 0;
    int lMove = 0;
    cin >> nCity >> lMove;
    int parent[kMax] = {0};
    for (int i = 0; i < nCity-1; ++i)
        cin >> parent[i];
    int dp[kMax] = {0};
    int maxMove = 0;
    for (int i = 0; i < nCity-1; ++i)
    {
        dp[i+1] = dp[parent[i]] + 1;
        maxMove = std::max(maxMove, dp[i+1]);
    }
    int d = std::min(maxMove, lMove);
    cout << min((nCity), 1 + d + (lMove-d)/2) << endl;
    
    return 0;
}
