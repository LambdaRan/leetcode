
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

#include <map>

//#include <stdio.h>


using namespace std;

int main()
{
    vector<int> v1 = {1,2,3};
    vector<char> v2 = {'A', 'B', 'C', 'D'};

    
    int v1Size = static_cast<int>(v1.size());
    int v2Size = static_cast<int>(v2.size());
    cout << v1[0] << v2[0];
    int i = 1,j = 1;
    while (!(i == j && i == 0))
    {
        cout << v1[i] << v2[j]; 
        i = (i+1)%v1Size;
        j = (j+1)%v2Size;
    }
    cout << endl;

    return 0;
}
