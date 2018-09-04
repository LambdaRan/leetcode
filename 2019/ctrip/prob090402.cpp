
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
    int nRecord = 0;
    cin >> nRecord;

    string aQuery = "";
    cin >> aQuery;

    vector<string> idVector;
    string id = "";
    string inTime = "";
    string outTime = "";
    for (int i = 0; i < nRecord; ++i)
    {
        cin >> id >> inTime >> outTime;
        if (aQuery >= inTime && aQuery <= outTime)
        {
            idVector.push_back(id);
        }
    }
    if (idVector.empty())
        cout << "null" << endl;
    sort(idVector.begin(), ididVector.end());
    copy(idVector.begin(), idVector.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
