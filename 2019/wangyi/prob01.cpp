

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int nColumn = 0;
    int mStep = 0;
    cin >> nColumn >> mStep;
    vector<int> allStep(nColumn);
    int column = 0;
    for (int i = 0; i < mStep; ++i)
    {
        cin >> column;
        ++allStep[column-1];
    }
    
    cout << *min_element(allStep.begin(), allStep.end());
    return 0;
}
