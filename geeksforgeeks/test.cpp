
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<bool> bvec;
    bvec.push_back(true);
    bvec.push_back(false);

    auto ret = bvec[0];

    return 0;
}
