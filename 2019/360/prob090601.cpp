
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

int calc(vector<int>& a, int n)
{
    if (n < 3 && a.size() < 3) return -1;
    else if (n == 3 && a.size() == 3)
        return 3;
    else  
    {
        for (size_t i = 3; i < a.size(); ++i)
        {
            vector<int> lin(a.begin(), a.begin()+1);
            sort(lin.begin(), lin.end(), greater<int>());
            int s1 = lin[0];
            int s2 = lin[1];
            int s3 = lin.back();
            if ((s1 + s2 > s3) && (s2 + s3 > s1) && (s3 + s1 > s2))
                return i;
            else if (a.size() > 3)
            {
                for (size_t j = 2; j < lin.size(); ++j)
                {
                    s1+=j;
                    vector<int> side = {s1,s2,s3};
                    sort(side.begin(), side.end(), greater<int>());
                     s1 = side[0];
                    s2 = side[1];
                    s3 = side.back();
                    if ((s1+s2>s3)&& (s2+s3>s1)&&(s3+s1>s2))
                        return i;
                }
            }
        }
        return -1;
    }

}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    vector<long> powinput(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
        powinput[i] = input[i] * input[i];
    }


    cout << calc(input, n) << endl;

    return 0;
}


