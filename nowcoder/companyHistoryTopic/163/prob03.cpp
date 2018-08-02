

//  交错01串

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    cin >> line;
    int max = 1;
    if (line.size() <= 1) 
        cout << 1 << endl;
    else 
    {
        int count = 1;
        for (size_t i = 1; i < line.size(); ++i)
        {
            if (line[i-1] != line[i])
                ++count;
            else 
            {
                max = max > count ? max : count;
                count = 1;
            }
        }
        if (count > 1)
            max = max > count ? max : count;
        cout << max << endl;
    }
        
    return 0;
}