

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
    int n, m;
    cin >> n >> m;
    int maxStep = 0;
    while (true)
    {
        if (m/2 == n)
        {
            maxStep += 1;
            break;
        }
        if (m % 2 == 0)
        {
            m = m/2;
            maxStep +=1;
        }
        else
        {
            m+=1;
            maxStep+=1;
        }
        if (m<n)
        {
            maxStep+=n-m;
            break;
        }
    }

    return 0;
}

