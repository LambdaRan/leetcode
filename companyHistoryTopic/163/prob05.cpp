

// 独立的小易

#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    int f = 0;
    int d = 0;
    int p = 0;
    cin >> x >> f >> d >> p;
    int day = d / x;
    day = day < f ? day : f + (d - f * x)/(p+x);
    cout << day << endl;       
  
    return 0;
}
