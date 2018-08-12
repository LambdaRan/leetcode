#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <cctype>

using namespace std;


string& trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<string> allDefine;
        istringstream input(line);
        string oneDefine;
        while (getline(input, oneDefine, ';'))
        {
            allDefine.push_back(trim(oneDefine));
        }
        
        unordered_map<string, string> wordMap;
        for (size_t i = 0; i < allDefine.size(); ++i)    
        {
            string trueLetter;
            string alise;
            string word;
            istringstream define(allDefine[i]);
            define >> word;
            if (word != "typedef")
            {
                cout << "none" << endl;
                return 0;
            }
            define >> trueLetter;
            if (trueLetter.empty())
            {
                cout << "none" << endl;
                return 0;  
            }
            define >> alise;
            if (alise.empty())
            {
                cout << "none" << endl;
                return 0;  
            }
            bool allletter = true;
            int index = 0;
            //cout << "word: " << trueLetter << endl;
            for (char ch : trueLetter)
            {
                if (!isalpha(ch))
                {
                    allletter = false;
                    break;
                }
                ++index;
            }

            if (allletter)
            {
                //cout << "alise: " << alise << " trueLetter: " << trueLetter << endl;
                wordMap[alise] = trueLetter;
            }
            else 
            {
                string tre = trueLetter.substr(0, index);
                //cout << "1tre: " << tre << endl;
                auto ret = wordMap.find(tre);
                if (ret != wordMap.end())
                {
                    tre = ret->second;
                }
                tre += trueLetter.substr(index);
                //cout << "alise: " << alise << " 2tre: " << tre << endl;
                wordMap[alise] = tre;
            }
            
            string empty;
            define >> empty;
            if (!empty.empty())
            {
                cout << "none" << empty << endl;
                return 0;
            }
        }
        
        string searchWord;
        cin >> searchWord;
        auto result = wordMap.find(searchWord);
        if (result != wordMap.end())
        {
            cout << result->second << endl;
        }
        else 
        {
            cout << "none" << endl;
        }
    }
    return 0;
}