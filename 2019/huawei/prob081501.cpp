

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main()
{

    string str;
    while (getline(cin, str))
    {
        std::vector<char> onlyChar;
        std::vector<int> alpha('z'-'0'); 
        for (char ch : str)
        {
            if (alpha[ch-'0'] != 1)
            {
                onlyChar.push_back(ch);
                alpha[ch-'0'] = 1;
            }
        }
        std::copy(onlyChar.begin(), onlyChar.end(), std::ostream_iterator<char>(std::cout));
        std::cout << std::endl;
    }
    return 0;
}