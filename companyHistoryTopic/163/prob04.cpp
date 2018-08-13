
// 操作序列

#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int NUM = 0;
    cin >> NUM;
    int input = 0;
    deque<int> oDeque;
    for (int i = 0; i < NUM; ++i)
    {
        cin >> input;
        if ((i+1)%2) oDeque.push_back(input);
        else oDeque.push_front(input);
    }
    if (NUM%2) std::copy(oDeque.rbegin(), oDeque.rend(), ostream_iterator<int>(cout, " "));
    else  std::copy(oDeque.begin(), oDeque.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}

