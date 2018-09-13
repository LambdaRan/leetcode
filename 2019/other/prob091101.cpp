
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
    int day = 0;
    cin >> day;
    vector<int> lights(10);
    lights[0] = 0;
    lights[9] = 0;
    for (int i = 1; i <= 8; ++i)
    {
        cin >> lights[i];
    }
    for (int i = 0; i < day; ++i)
    {
        vector<int> curLights(lights);
        for (int j = 1; j <= 8; ++j)
        {
            if (lights[j-1] == lights[j+1])
                curLights[j] = 0;
            else  
                curLights[j] = 1;
        }
        lights = curLights;
    }
    for (int i = 1; i < 8; ++i)
    {
       cout << lights[i] << " ";
    }
    cout << lights[8] << endl;
    return 0;
}
