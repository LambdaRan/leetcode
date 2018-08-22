
#include <iostream>
#include <vector>

using namespace std;

int longest(string s) 
{
    int maxLength = 0;
    int preError = -1;
    vector<int> oldLetterIndexVec;
    for(int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            oldLetterIndexVec.push_back(i);
        }
        else if (s[i] == ')') 
        {
            if (oldLetterIndexVec.size() > 0)
            {
                oldLetterIndexVec.pop_back();
                int curLen;
                if (oldLetterIndexVec.size() == 0)
                    curLen = i - preError;
                else 
                    curLen = i - oldLetterIndexVec.back();

                if (curLen > maxLength) 
                    maxLength = curLen;
            }
            else
                preError = i;
        }
        else 
        {
            oldLetterIndexVec.clear();
            preError = i;
        }
    }
    return maxLength;
}

int main()
{

    string str;
    while (getline(cin, str))
    {
        int result = longest(str);
        cout << result << endl;
    }
    return 0;
}