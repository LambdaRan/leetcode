

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int countWords(const char* str, size_t size)
{
    size_t slow = 0;
    size_t fast = 0;
    int ret = 0;
    while (fast < size) {
        if (str[fast] == ' ' | str[fast] == '\t' |
            str[fast] == ',' | str[fast] == '.')
        {
            if (fast-slow > 0) {
                ++ret;
                slow = fast+1;
            } else {
                slow = fast+1;
            }
        }
        ++fast;
    }
    if (fast - slow > 0)
        ++ret;
    return ret;
}
// 6 3 8 6 9 7 6
int main()
{
    string in;
    while (getline(std::cin, in)) {
        int w = countWords(in.c_str(), in.size());
        cout << w << endl;
    }

    return 0;
}