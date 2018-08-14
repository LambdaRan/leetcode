

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <iterator>

using namespace std;

int main()
{

    string str;
    while (getline(cin, str))
    {
        std::set<char> onlyChar;
        std::vector<int> alpha('z'-'A'); 
        for (char ch : str)
        {
            if (alpha[ch-'A'] == 1)
                onlyChar.insert(ch);
            else  
                alpha[ch-'A'] = 1;
        }
        std::copy(onlyChar.begin(), onlyChar.end(), std::ostream_iterator<char>(std::cout));
        std::cout << std::endl;
    }
    return 0;
}