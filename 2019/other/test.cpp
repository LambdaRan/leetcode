
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a,b,c,d;

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c >> d;
        string result;
        result += ('0'+a);
        result += ('0'+b);
        result += ('0'+c);
        int r1 = 3;
        //int r2
        while (r1 <= d)
        {
            a = result[0] - '0';
            b = result[1] - '0';
            c = result[2] - '0';
            string sum = to_string(a+b+c);
            if (sum.size()==2)
            {
                result[0] = result[1];
                result[1] = sum[0];
                result[2] = sum[1];
            }
            else 
            {
                result[0] = result[1];
                result[1] = result[2];
                result[2] = sum[0];
            }
            r1 += sum.size();
        }
        cout << result[d-r1+2] << endl;
    }
    return 0;
}
