
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

#include <map>

//#include <stdio.h>

using namespace std; 

int lst[100005]; 

int main()
{     
	int n;     
	while ( cin >> n )
	{         
		vector<int> nodeDepth(100005, 0); 
        int maxDepth = 0;
		for (int i = 0; i< n-1; ++i)
		{             
			int a,b;             
			cin >> a >> b;
            // 当前节点的深度
            nodeDepth[b] = nodeDepth[a] + 1;
			maxDepth = max(nodeDepth[b], maxDepth);        
		}        
        int minLost = 2*n-2-maxDepth; 
        cout << minLost << endl;   
	}     
	return 0; 
}
