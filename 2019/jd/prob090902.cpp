#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item {
    int a;
    int b;
    int c;
    bool flag = false;
    
    item(int x, int y, int z)
        : a(x), b(y), c(z) { }
};

bool compare(const item& lhs, const item& rhs)
{
    return (rhs.a > lhs.a && rhs.b > lhs.b && rhs.c > lhs.c);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<item> v;
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.emplace_back(a, b, c);
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v.size(); ++j)
        {
            if (compare(v[i], v[j]) && v[i].flag == false)
            {
                ++cnt;
                v[i].flag = true;
                break;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
