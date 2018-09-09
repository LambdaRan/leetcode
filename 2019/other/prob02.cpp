
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
    int nPoint = 0;
    cin >> nPoint;
    vector<int> beans(nPoint);
    for (int i = 0; i < nPoint; ++i)
    {
        cin >> beans[i];
    }
    int maxBeans = 0;
    for (int i = 0; i < nPoint; ++i)
    {
        int curBeans = 0;
        int j = i;
        while (j < nPoint)
        {
            curBeans += beans[i];
            if (curBeans % 2 == 1)
                j += 2;
            else  
                j += 3;
        }

        j = (j + nPoint) % nPoint;
        while (j < i)
        {
            curBeans += beans[j];
            if (curBeans % 2 == 1)
                j += 2;
            else  
                j += 3;
        }

        maxBeans = max(maxBeans, curBeans);
    }

    cout << maxBeans << endl;

    return 0;
}
