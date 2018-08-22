
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string maxLength(string str)
{     
    size_t len = str.size();
    vector<string> arr(len);
    for(size_t i = 0; i < len; i++)
        arr[i] = str.substr(i);

    vector<string> carr(arr);
    std::sort(arr.begin(), arr.end());
    int max = 0;
    size_t index = 0;
    for (size_t i = 0; i < arr.size()-1; ++i) 
    { 
        string str1 = arr[i];
        string str2 = arr[i+1];
        int count = 0;
        for (size_t j = 0; j < str1.size() && j < str2.size(); ++j) 
        {
            if(str1[j] == str2[j]) 
            {
                count++;
                if(count > max) 
                {
                    max = count;
                    index = i;
                }
            } 
            else 
            { 
                break;
            }
        }
    }
    if(max == 0)
        return " 0";
    else 
    {
        string result;
        string tmp = arr[index].substr(0, max);
        result.append(tmp);
        result.append(" ");
        result.append(std::to_string(tmp.size()));
        return result;
    }
}
int main()
{

    string line;
    while (getline(cin, line))
    {
        cout << maxLength(line) << endl;
    }
    return 0;
}