
#include <iostream>
#include <cassert>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<size_t> maxstr;
        set<char> str;
        for (int i = 0; i < s.size(); ++i) {
            auto res = str.insert(s[i]);
            if (!res.second) {
                maxstr.insert(str.size());
                i = i - str.size();
                str.clear();         
            }
        }
        //cout << str.size() << endl;
        maxstr.insert(str.size());

        for (auto n:maxstr)
            cout << n << " ";
        cout << endl;
        if (maxstr.size() == 1)
            return *maxstr.begin();
        else
            return *maxstr.end();
        //return *maxstr.end();
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}