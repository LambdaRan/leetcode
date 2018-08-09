
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 871. Minimum Number of Refueling Stops
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        if (startFuel >= target) return 0;
        if (stations.empty()) return -1;
        if (startFuel < stations[0][0]) return -1;

        vector<long> farthest(500+1);
        farthest[0] = startFuel;
        int staSize = static_cast<int>(stations.size());
        //cout << staSize << endl;
        for (int i = 0; i < staSize; ++i)
        {
            for (int j = i; j >= 0 && farthest[j] >= stations[i][0]; --j)
            {
                farthest[j+1] = std::max(farthest[j+1], farthest[j]+stations[i][1]);
            }
        }
        for (int i = 0; i <= staSize; ++i)
        {
            //cout << farthest[i] << endl;
            if (farthest[i] >= target)
                return i;
        }
        return -1;
    }


};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    vector<vector<int>> stations = {{50,50}};

    int result = s.minRefuelStops(100, 50, stations);
    cout << result;
    std::cout << std::endl;
    return 0;
}

    // int _minRefuelStops(int target, 
    //                     int startFuel, 
    //                     vector<vector<int>>& stations,
    //                     size_t start,
    //                     int preFuel)
    // {
    //     if (startFuel >= target) return 0;
    //     if (stations.empty()) return -1;
    //     if (start == stations.size()-1) return -1;
    //     if (start == 0)
    //     {
    //         if (startFuel < stations[start][0]) return -1;
    //     }
    //     else 
    //     {
    //         int curFuel = stations[start][0] - preFuel;
    //         if (startFuel < curFuel) return -1;
    //     }

    //     cout << "start:" << start << endl;
    //     size_t maxDriveStation = start;
    //     for (size_t i = start; i < stations.size(); ++i)
    //     {
    //         if (startFuel >= stations[i][0])
    //             maxDriveStation = i;
    //         else 
    //             break;
    //     }
    //     cout << "maxDriveStation:" << maxDriveStation << endl;
    //     int curCount = -1;
    //     int stime = 16;
    //     for (size_t i = maxDriveStation; i >= start; --i)
    //     {
    //         int curTarget = target - stations[i][0];
    //         int curStartFuel = startFuel - (stations[i][0] - stations[start][0]) + stations[i][1];
    //         size_t curStart = i;
    //         curCount = _minRefuelStops(curTarget, curStartFuel, stations, curStart, stations[i][0]);
    //         cout << "curTarget:" << curTarget 
    //             << " curStartFuel:" << curStartFuel 
    //             << " curStart:" << curStart 
    //             << "curCount:" << curCount << endl;
    //         if (curCount >= 0) break;

    //         --stime;
    //         if (stime < 0) break;
    //     }
    //     cout << "curCount:" << curCount << endl;
    //     if (curCount < 0) return -1;
    //     else  
    //         return curCount + 1;
    // }