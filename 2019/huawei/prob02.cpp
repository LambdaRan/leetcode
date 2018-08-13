#include <iostream>
#include <string>
#include<sstream>


using namespace std;


int knapsack(int *W, int *V, int *res, int n, int C)
{
    int value = 0;
    int **f = new int*[n];
    for(int i = 0; i < n; i++)
    {
        f[i] = new int[C+1];
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= C;j++)
            f[i][j] = 0;

    for(int i = 0; i < n; i++)
    {
        f[i][0] = 0;
    }
    for(int i = 1; i <= C; i++)
    {
        f[0][i] = (i < W[0])?0:V[0];
    }
    for(int i = 1; i < n; i++)
    {
        for(int y = 1; y <= C; y++)
        {
            if(y >= W[i])
            {
                f[i][y] = (f[i-1][y] > (f[i-1][y-W[i]] + V[i]))?f[i-1][y]:(f[i-1][y-W[i]] + V[i]);
            } else {
                f[i][y] = f[i-1][y];
            }
        }
    }
    value = f[n-1][C];
    int j = n-1;
    int y = C;
    while(j)
    {
        if(f[j][y] == (f[j-1][y-W[j]] + V[j]))
        {
            res[j] = 1;
            y = y - W[j];
        }
        j--;
    }
    if(f[0][y])
    {
        res[0] = 1;
    }

    for(int i = 0; i < n;i++)
    {
        delete f[i];
        f[i] = 0;
    }
    delete [] f;
    f = 0;
    return value;
}

int main()
{
    int v[5];
    int w[5];
    int res[5];
    int c = 0;
    for(int i = 0; i < 5; ++i)
        res[i] = 0;
        
    string line;
    getline(cin, line);
    istringstream is(line);
    int inter;
    char ch;
    int i = 0;
    while (is >> inter)
    {
        v[i++] = inter;
        is >> ch;
    }
    getline(cin, line);
    istringstream is2(line);
    i = 0;
    while (is2 >> inter)
    {
        w[i++] = inter;
        is2 >> ch;
    }
    
    cin >> c;
    
    int value = knapsack(w, v, res, 5, c);
    cout << value << endl;
    
    return 0;
}