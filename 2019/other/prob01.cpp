

#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>


using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        int cMaxMove = 0;
        int dMaxMove = 0;
        int cCount = 0;
        int dCount = 0;
        for (char ch : line)
        {
            if (ch == 'C')
            {
                cMaxMove += dCount;
                ++cCount;
            }
            else  
            {
                dMaxMove += cCount;
                ++dCount;
            }
        }
        cout << std::min(cMaxMove, dMaxMove) << endl;
    }

    return 0;
}
