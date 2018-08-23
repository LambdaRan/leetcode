
#include <iostream>
#include <algorithm>
#include <functional>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> threeNum(3);
    cin >> threeNum[0] >> threeNum[1] >> threeNum[2];
    std::sort(threeNum.begin(), threeNum.end());
    if (threeNum[0] == 1)
    {
        int result = (threeNum[0]+threeNum[1])*threeNum[2];
        cout << result << endl;
    }
    else  
    {
        int result = std::accumulate(threeNum.begin(), threeNum.end(), 1, std::multiplies<int>());
        cout << result << endl;
    }
    return 0;
}
