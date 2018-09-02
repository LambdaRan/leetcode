#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char* argv[])
{
    int num = 0;
    vector<int> vec;
    while (cin >> num)
    {
        int number;
        for (int i = 0; i < num; ++i)
        {
            cin >> number;
            vec.push_back(number);
        }
        
        std::sort(vec.begin(), vec.end());
        int diff = vec[1] - vec[0];
        bool istrue = true;
        for (int i = 2; i <= num-1; ++i)
        {
            if (vec[i] - vec[i-1] != diff)
            {
                istrue = false;
                cout << "Impossible" << endl;
                break;
            }
        }
        if (istrue)
            cout << "Possible" << endl;
    }
    
    return 0;
}