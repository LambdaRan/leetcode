
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int nMachine = 0;
    int mTask = 0;
    cin >> nMachine >> mTask;
    typedef std::pair<int, int> Entity;
    std::vector<Entity> machineInfo(nMachine);
    { // 输入机器信息
        int zi = 0;
        int wi = 0;
        for (int i = 0; i < nMachine; ++i)
        {
            cin >> zi >> wi;
            machineInfo[i] = std::make_pair(zi, wi);
        }
    }
    std::vector<Entity> taskInfo(mTask);
    { // 输入任务信息
        int xi = 0;
        int yi = 0;
        for (int i = 0; i < mTask; ++i)
        {
            cin >> xi >> yi;
            taskInfo[i] = std::make_pair(xi, yi);
        }
    }
    // 将任务按完成时间递增排序,并按难度递增排序
    std::sort(taskInfo.begin(), taskInfo.end());
    std::sort(machineInfo.begin(), machineInfo.end());

    // cout << "test\n";
    // for (size_t i = 0; i < taskInfo.size(); ++i)
    //     cout << taskInfo[i].first << " " << taskInfo[i].second << "\n";
    // cout << endl;
    // cout << endl;
    // for (size_t i = 0; i < machineInfo.size(); ++i)
    //     cout << machineInfo[i].first << " " << machineInfo[i].second << "\n";
    // cout << endl;

    long long maxIncome = 0;
    int maxTaskNum = 0;
    int machineIndex = static_cast<int>(nMachine-1);
    vector<int> count(105);
    for (auto every = taskInfo.rbegin(); every != taskInfo.rend(); ++every)
    {
        // auto lowerIter = std::lower_bound(machineInfo.begin(), machineInfo.end(), *every);
        
        // while(lowerIter != machineInfo.end())
        // {
        //     if (lowerIter->second >= every->second)
        //     {
        //         ++maxTaskNum;
        //         maxIncome += 200 * every->first + 3 * every->second;
        //         machineInfo.erase(lowerIter);
        //         break;
        //     }
        //     ++lowerIter;
        // }
        
        // if (lowerIter != machineInfo.end())
        // {
        //     ++maxTaskNum;
        //     maxIncome += 200 * every->first + 3 * every->second;
        //     machineInfo.erase(lowerIter);
        // }

        while (machineIndex >= 0 && machineInfo[machineIndex].first >= every->first)
        {
            ++count[machineInfo[machineIndex].second];
            --machineIndex;
        }
        for (int k = every->second; k <= 100; ++k)
        {
            if (count[k])
            {
                --count[k];
                ++maxTaskNum;
                maxIncome += 200 * every->first + 3 * every->second;
                break;
            }
        }
    }
    cout << maxTaskNum << " " << maxIncome << endl;


    return 0;
}
