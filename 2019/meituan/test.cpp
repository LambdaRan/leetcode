
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
    int nInter = 0;
    cin >> nInter;
    int first, second;
    for (int i = 0; i < nInter; ++i)
    {
        cin >> first >> second;


    }

    cout << nInter << endl;

    return 0;
}
#include<bits/stdc++.h> using namespace std; int lst[100005]; int main(){     int n;     while(cin>>n){         memset(lst,0,sizeof(lst));         for(int i = 0;i<n-1;i++){             int a,b;             cin>>a>>b;             lst[b] = lst[a]+1;//当前节点的深度         }         int depth = 0;         for(int i = 1;i<=n;i++)             depth = lst[i]>depth?lst[i]:depth;//找到最大值         cout<<2*n-2-depth<<endl;     }     return 0; }
