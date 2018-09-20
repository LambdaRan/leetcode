

#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
//#include <stdio.h>
using namespace std;

vector<string> strSplit(const string& str, char dem)
{
    vector<string> vs;
    size_t start = 0;
    size_t size = str.size();
    while (start < size)
    {
        auto ret = str.find_first_of(dem, start);
        ret = (ret == string::npos) ? size : ret;
        vs.emplace_back(str.substr(start, ret-start));
        start = ret + 1;
    }
    return vs;
}


// int minDistance(string word1, string word2) 
// {
//     int m=static_cast<int>(word1.size());
//     int n=static_cast<int>(word2.size());
//     vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//     for(int i=0; i<m+1; i++)
//         dp[i][0] = i;
//     for(int j=0; j<n+1; j++)
//         dp[0][j] = j;
//     for(int i=1;i<m+1;i++)
//     {
//         for(int j=1;j<n+1;j++)
//         {
//             if(word1[i-1] == word2[j-1])
//                 dp[i][j] = dp[i-1][j-1];
//             else
//                 dp[i][j] = min(dp[i-1][j-1]+2, min(dp[i-1][j]+3, dp[i][j-1]+3));
//         }
//     }
//     return dp[m][n];
// }

int main()
{
    string line;
    getline(cin, line);
    vector<string> words = strSplit(line, ' ');
    string target = words.front();
    words.erase(words.begin());
    vector<pair<int, int>> sequ;
    int score = 0;
    for (size_t i = 0; i < words.size(); ++i)
    {
        score = minDistance(target, words[i]);
        sequ.emplace_back(make_pair(score, i));
    }
    sort(sequ.begin(), sequ.end(), [](const pair<int, int>& v1, const pair<int, int>& v2){
        if (v1.first == v2.first)
            return v1.second < v2.second;
        return v1.first < v2.second;
    });

    for (size_t i = 0; i < 2; ++i)
        cout << words[sequ[i].second] << " ";
    cout << words[sequ[2].second] << endl;
    return 0;
}

