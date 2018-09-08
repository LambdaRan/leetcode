

#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    int t = 0;
    while (cin >> t)
    {
        while (t--)
        {
            string s = "";
            cin >> s;
            if (s.length() < 4) 
            {
               cout << s << endl;
            } 
            else 
            {
                int count = 1;
                map<int, int> mapp;
                for (int i = 1; i < s.length(); i++) 
                {
                    if ((s[i] - s[i-1]) == 1) 
                    {
                        count++;
                    } 
                    else 
                    {
                        if (count >= 4) 
                            mapp[i-count] = count;
                        count = 1;
                    }
                }
                if (count >= 4) 
                {
                    if ((s[s.length() - 1] - s[s.length() - 2]) == 1) 
                        mapp[s.length() - count] =  count;
                }
                string ss = "";
                int k = mapp.size();
                int i = 0;
                while (i < s.length()) 
                {
                    ss += s[i];
                    auto it = mapp.find(i);
                    if (k != 0 && it != mapp.end())
                    {
                        i = i + mapp[i] - 1;
                        ss += "-";
                        ss += s[i];
                    }
                    i++;
                }
                cout << ss << endl;
            }
        }
    }

    return 0;
}


