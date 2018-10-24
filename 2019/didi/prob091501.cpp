
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

using namespace std;

vector<string> split(string str, const string& pattern)
{
    vector<string> ret;

    int size = str.size();
    int i = 0;
    while (i < size)
    {
        auto pos = str.find_first_of(pattern, i);
        pos = (pos == string::npos) ? size : pos;
        ret.emplace_back(str.substr(i, pos - i));
        i = pos + 1;
    }
    return ret;
}

int minDistance(string word1, string word2) 
{
    int m=static_cast<int>(word1.size());
    int n=static_cast<int>(word2.size());
    if (!m || !n)   return max(m, n);
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) 
        {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1]+2, min(dp[i-1][j]+3,dp[i][j-1]+3));
        }
    }
    return dp[m][n];
}
struct Word 
{
    string w;
    int index;
    int mod;
    Word(string str, int i, int m) 
        : w(str), index(i), mod(m) 
    { }
};

int main()
{
    string line;
    getline(cin, line);

    vector<string> words = split(line, " ");
    string target = words[0];
    words.erase(words.begin());
    vector<Word> wword;
    for (int i = 0; i < words.size(); ++i)
    {
        int mod = minDistance(target, words[i]);
        wword.emplace_back(words[i], i, mod);
    }
    
    sort(wword.begin(), wword.end(),[](const Word& w1, const Word& w2){
        if (w1.mod == w2.mod) 
            return w1.index < w2.index;
        return w1.mod < w2.mod;
    });

    if (wword.size() < 3)
    {
        for (size_t i = 0; i < wword.size()-1; ++i)
            cout << wword[i].w << " ";
        cout << wword.back().w << endl;
    }
    else
    {
        for (size_t i = 0; i < 2; ++i)
             cout << wword[i].w << " ";
        cout << wword[2].w << endl;
    }

    return 0;
}
