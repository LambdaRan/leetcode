
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

#include <stdio.h>

using namespace std;

void modify(vector<bool>& rela, int row, int col, int md)
{
	if (rela[row * md + col]) 
    {
		rela[row * md + col] = false;
		if (col + 1 < md)
			modify(rela, row, col + 1, md);
		if (row + 1 < md)
			modify(rela, row + 1, col, md);
	}
}
int main()
{
    int MDepart = 0;
	cin >> MDepart;
    vector<bool> rela(MDepart * MDepart, 0);

    int inNum = 0;
	for (int i = 0; i < MDepart; ++i) 
    {
		for (int j = 0; j < MDepart; ++j) 
        {
			scanf("%d", &inNum);
			if (inNum)
				rela[i * MDepart + j] = true;
		}
	}
    int result = 0;
	for (int i = 0; i < MDepart; ++i) 
    {
		for (int j = 0; j < MDepart; ++j) 
        {
			if (rela[i * MDepart + j]) 
            {
				modify(rela, i, j, MDepart);
				++result;
			}
		}
	}
	cout << result << endl;
    return 0;
}
