
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

#include <cstdio>


using namespace std;

int main()
{
    int nTime = 0;
    scanf("%d", &nTime);
    char everyTime[9];
    int hour, minutes, second;
    while (nTime--)
    {
        sscanf(everyTime, "%d:%d:%d", &hour, &minutes, &second);
        if (hour > 23)  hour %= 10;
        if (minutes > 59) minutes %= 10;
        if (second > 59) second %= 10;
        printf("%2d:%2d:%2d", hour, minutes, second);
    }
    //printf("%d %d %d\n", hour, minutes, second);
    //if ()

    // int nTime = 0;
    // char everyTime[9];
    // const char maxTime[] = {"23:59:59"};
    // const int timeIndex[] = {0,3,6};
    // scanf("%d", &nTime);
    // vector<string> result(nTime);
    // int i = 0;
    // while (nTime--)
    // {
    //     scanf("%s", everyTime);
    //     if (everyTime[1] > maxTime[1])
    //     {
    //         everyTime[0] = (everyTime[0] >= '2') ? '0' : everyTime[0];
    //     }
    //     for (int idx : timeIndex)
    //     {
    //         if (everyTime[idx] > maxTime[idx])
    //             everyTime[idx] = '0';
    //     }
    //     result[i++] = everyTime;
    // }

    // for (string& str : result)
    //     printf("%s\n", str.c_str());
    return 0;
}

