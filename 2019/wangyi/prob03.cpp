
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 苹果问题

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
    
    vector<long> sumHeap(nHeap);
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
        auto ret =  std::lower_bound(sumHeap.begin(), sumHeap.end(), qi[i]);
        //size_t diff = ret - sumHeap.begin();
        size_t diff = std::distance(ret, sumHeap.begin());
        cout << diff+1 << endl;
    }

    return 0;
}   
