
// #include <iostream>

// using namespace std;

// int main()
// {
//     int nums[8];
//     for (int i = 0; i < 8; ++i)
//         nums[i] = 0;

//     int a,b;
//     while (true)
//     {
//         scanf("%d,%d",&a,&b);
//         if (a == -1 && b == -1 )
//             break;
//         for (int k = a;k<b;k++)
//             nums[k-12]++;
//     }

//     for (int i = 0; i<8; i++)
//         printf("[%d,%d):%d\n",(i+12),(i+13),nums[i]);
// }


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int start = 0; 
    int end = 0;
    char ch = 0;
    vector<int> total(20-12);
    while (true)
    {
        cin >> start >> ch >> end;
        if (start == -1 || end == -1)
            break;
        for (int i = start; i < end; ++i)
            ++total[i-12];
    }
    for (size_t i = 0; i < total.size(); ++i)
    {
        cout << "[" << (i+12) << "," << (i+13) << "):" << total[i] << endl;
    }
    return 0;
}
// 12,15
// 16,17
// 12,20
// -1,-1

