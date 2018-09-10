#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> strSplit(const string& str, char dem)
{
    vector<int> vs;
    size_t start = 0;
    size_t size = str.size();
    while (start < size)
    {
        auto ret = str.find_first_of(dem, start);
        ret = (ret == string::npos) ? size : ret;
        vs.emplace_back(stoi(str.substr(start, ret-start)));
        start = ret + 1;
    }
    return vs;
}

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;

    vector<int> v = strSplit(str, ',');
    int step1 = 0, step2 = 0;
    for (int i= 2; i <= v.size(); ++i)
    {
        int temp = min(step1 + v[i-1], step2 + v[i-2]);
        step2 = step1;
        step1 = temp;
    }
    cout << step1 << endl;

    return 0;
}
