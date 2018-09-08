
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>

//#include <stdio.h>

using namespace std;

struct Log {
    string time;
    int hostId;
    string logText;

    Log(string t, int id, string text)
        : time(t), hostId(id), logText(text) { }
};

int main(int argc, char const *argv[])
{
    int N;  // 日志行数
    cin >> N;
    vector<Log> logs(N);
    typedef vector<Log>::iterator VLIter;
    map<int, VLIter> idMap;
    string timeStr;
    int hostId;
    string logText;
    for (int i = 0; i < N; ++i)
    {
        cin >> timeStr >> hostId >> logText;
        logs[i] = Log(timeStr, hostId, logText);
    }
    
    cout << "Logs: " << endl;
    for (auto l : logs)
        cout << l.time << " " << l.hostId << " " << l.logText << endl;
    return 0;
}
