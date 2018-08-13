

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <map>

using namespace std;

// 阿里 编程测验
// 今天我们看到的阿里巴巴提供的任何一项服务后边都有着无数子系统和组件的支撑，子系统之间也互相依赖关联，
// 其中任意一个环节出现问题都可能对上游链路产生影响。小明做为新人接收到的第一个任务就是去梳理所有的依赖关系，
// 小明和每个系统的负责人确认了依赖关系，记录下调用对应系统的耗时，用这些数据分析端到端链路的数目和链路上最长的耗时。

// 输入： 小明搜集到的系统耗时和依赖列表
// 5  4   // 表示有5个系统和 4个依赖关系
// 3      // 调用1号系统耗时 3 ms
// 2      // 调用2号系统耗时 2 ms
// 10     // 调用3号系统耗时 10 ms
// 5      // 调用4号系统耗时 5 ms
// 7      //  调用5号系统耗时 7 ms
// 1 2    //  2号系统依赖1号系统
// 1 3    //  3号系统依赖1号系统
// 2 5    //  2号系统依赖5号系统
// 4 5    //  4号系统依赖5号系统

// 输出:  调用链路的数目 和最大的耗时， 这里有三条链路1->2->5，1->3， 4->5，最大的耗时是1到3的链路 3+10 = 13，无需考虑环形依赖的存在。
// 3  13

typedef map<int, vector<int>> RelaMapPtr;
void graphDFS(RelaMapPtr& graph, 
                vector<int>& isVist, 
                vector<int>& vistSet,
                vector<vector<int>>& path, 
                int next)
{
    vistSet.push_back(next);
    isVist[next-1] = 1;
    RelaMapPtr::iterator ret = graph.find(next);
    if (ret != graph.end())
    {
        for (size_t i = 0; i < ret->second.size(); ++i)
        {
            graphDFS(graph, isVist, vistSet, path, ret->second[i]);
        }
    }
    else  
    {
        path.push_back(vistSet);
    }
    vistSet.pop_back();
}

int main()
{
    int nSys = 0;
    int nRela = 0;
    cin >> nSys >> nRela;
    int inNum = 0;
    vector<int> sysLost(nSys);
    for (int i = 0; i < nSys; ++i)
    {
        cin >> inNum;
        sysLost[i] = inNum;
    }

    map<int, vector<int>> relaMap;
    int first = 0;
    int second = 0;
    for (int i = 0; i < nRela; ++i)
    {
        cin >> first >> second;
        relaMap[first].push_back(second);
    }

    vector<vector<int>>  allPath;
    vector<int> bit(nSys);
    vector<int> onePath;
    for (RelaMapPtr::iterator it = relaMap.begin(); it != relaMap.end(); ++it)
    {
        // cout << "it->first: " << it->first << " ";
        // std::copy(it->second.begin(), it->second.end(), std::ostream_iterator<int>(std::cout, " "));
        // cout << endl;

        if (bit[it->first - 1] == 0) 
        {
            graphDFS(relaMap, bit, onePath, allPath, it->first);
        }
    }

    // cout << "allPath: " << endl;
    // for (size_t i = 0; i < allPath.size(); ++i)
    // {
    //     std::copy(allPath[i].begin(), allPath[i].end(), std::ostream_iterator<int>(std::cout, " "));
    //     cout << endl;
    // }
    int maxLost = 0;
    for (size_t i = 0; i < allPath.size(); ++i)
    {
        int curLost = std::accumulate(allPath[i].begin(), allPath[i].end(), 0, 
                        [&](const int& sum, const int& curValue) {
                            return sum + sysLost[curValue-1];
                        });
        maxLost = std::max(maxLost, curLost);
    }
    cout << allPath.size() << " " << maxLost << endl;   
    return 0;
}
