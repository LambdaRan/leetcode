
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>


using namespace std;

int getMin(int* step, int i, int j) 
{
    int min = 1000000;
    for (int k = i; k <= j; k++) 
    {
        if (step[k] < min) {
            min = step[k];
        }
    }
    return min;
}
int main()
{
    int xLocal = 0;
    while (cin >> xLocal)
    {
        int step [xLocal + 1];
        if (xLocal <= 5)
            cout << 1 << endl;
        else  
        {
            for (int i = 1; i <= 5; i++) 
                step[i] = 1;
            for (int i = 6; i <= xLocal; i++) {
                step[i] = getMin(step, i - 5, i - 1) + 1;
            }
            cout << step[xLocal] << endl;
        }
    }
    return 0;
}
