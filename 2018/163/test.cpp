#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nHeap = 0;
    cin >> nHeap;
    vector<int> countPerHeap;
    int count = 0;
    for (int i = 0; i < nHeap; ++i)
    {
        cin >> count;
        countPerHeap.push_back(count);
    }
    
    vector<long> sumHeap(nHeap+1);
    long sum = 0;
    for (int i = 0; i < nHeap; ++i)
    {
        sum += countPerHeap[i];
        sumHeap[i] = sum;
    }
    
    int mAsk = 0;
    cin >> mAsk;
    vector<int> qi;
    for (int i = 0; i < mAsk; ++i)
    {
        cin >> count;
        qi.push_back(count);
    }
    
    for (int i = 0; i < mAsk; ++i)
    {
        for (int j = 0; j < nHeap; ++j)
        {
            if (qi[i] <= sumHeap[j])
            {
                cout << j << endl;
                break;
            }
        }
    }

    return 0;
}   