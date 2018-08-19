

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int nCity = 0;
    cin >> nCity;
    vector<long> high(nCity);
    for (int i = 0; i < nCity; ++i)
    {
        cin >> high[i];
    }
    std::sort(high.begin(), high.end());

    long minCost = std::accumulate(high.begin(), high.end(), 0) - high[0];
    cout << minCost << endl;
    return 0;
}
