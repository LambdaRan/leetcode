
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string str;
    
    while (std::getline(std::cin, str))
    {
        for (char& s : str)
        {
            if (isalpha(s))
            {
                if (islower(s))
                    s = toupper(s);
                else
                    s = tolower(s);
            }
        }

       cout << str <<endl;        
    }

   return 0;
}

        // std::transform(str.begin(), str.end(), str.begin(), 
        // [](unsigned char c) -> unsigned char { return std::toupper(c); });

