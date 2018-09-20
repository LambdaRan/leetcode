

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

vector<int> strSplit(string input, char delim) 
{
    vector<int> output;
    // trimLeftTrailingSpaces(input);
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
    // trimRightTrailingSpaces(input);
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
    //input = input.substr(1, input.length() - 2);
    istringstream ss(input);
    // ss.str(input);
    string item;
    // char delim = ',';
    while (getline(ss, item, delim)) {
        output.emplace_back(stoi(item));
    }
    return output;
}

struct Node {
    int idx;
    int mdi;
    int mwi;
    bool mdel;
    Node(int c, int a, int b):idx(c), mdi(a), mwi(b), mdel(false){}
};

int main()
{
    string line;
    getline(cin, line);
    vector<int> di = strSplit(line, ',');
    getline(cin, line);
    vector<int> wi = strSplit(line, ',');
    map<int, int> dc;
    vector<Node> nodes;
    for (size_t i = 0; i < di.size(); ++i)
    {
        nodes.emplace_back(Node(i+1, di[i], wi[i]));
        ++dc[di[i]];
    }
    sort(nodes.begin(), nodes.end(), [](const Node& n1, const Node& n2){
        return n1.mdi < n2.mdi;
    });
    for (auto it = dc.begin(); it != dc.end(); ++it)
    {
        if (it->second > 1)
        {
            auto ret1 = it->second - 1;
            //auto las = find_first_of(nodes.rbegin(), nodes.rend(), it->first);
            size_t i = 0;
            for (i = nodes.size()-1; i >= 0; --i)
            {
                if (nodes[i].mdi == it->first)
                    break;
            }
            //Node tm = *las;
            sort(nodes.begin(), nodes.begin()+i, [](const Node& n1, const Node& n2){
                return n1.mwi < n2.mwi;
            });
            for (int i = 0, j = 0; i < ret1; ++j)
            {
                if (nodes[j].mdel == false)
                {
                    nodes[j].mdel = true;
                    ++i;
                }
            }
        }
    }   
    size_t count = count_if(nodes.begin(), nodes.end(), [](const Node& v){
        return v.mdel == false;
    });
    // nodes.erase(nodes.begin(), nodes.end(), []);
    sort(nodes.begin(), nodes.end(), [](const Node& n1, const Node& n2){
        return n1.mdi < n2.mdi;
    });
    for (auto it = nodes.begin(); it != nodes.end() && count >= 1; ++it)
    {
        if (count == 1 && !it->mdel)
        {
            cout << "a" <<it->idx << endl;
            break;
        }

        if (!it->mdel)
        {
            cout << "a" <<it->idx << ",";
            --count;
        }

    }
    //if (nodes.back().mdel == false)
    //    cout << "a" <<nodes.back().idx << endl;
    //cout << endl;
    return 0;
}

