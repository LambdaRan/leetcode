
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 401. Binary Watch
* Description: 
* A binary watch has 4 LEDs on the top which represent the hours (0-11), 
* and the 6 LEDs on the bottom represent the minutes (0-59).
* Each LED represents a zero or one, with the least significant bit on the right.
* Given a non-negative integer n which represents the number of LEDs that are currently on, 
* return all possible times the watch could represent.
* 
* Example:
* Input: n = 1
* Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
* 
* Note:
* The order of output does not matter.
* The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
* The minute must be consist of two digits and may contain a leading zero, 
*   for example "10:2" is not valid, it should be "10:02".
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<string> readBinaryWatch(int num) {
        if (num <= 0) return vector<string>({"0:00"});
        vector<string> result;
        if (num > 8) return result;

        vector<char> perBit = {'0','0','0','0','0','0','0','0','0','0'};
        
        _timesRecursive(perBit, 0, 0, num, result); 
        // 返回的是逆序，所以逆序返回       
        return std::vector<string>(result.rbegin(), result.rend());
    }
private:
    void _timesRecursive(vector<char>& bits,
                        int index, 
                        int count, 
                        int num, 
                        vector<string>& result)
    {
        if (count == num)
        {
            int hours = 0;
            int minutes = 0;
            vector<int> bitTimeMap = {8,4,2,1,32,16,8,4,2,1}; 
            //std::cout << std::string(bits.begin(), bits.end()) << std::endl;       
            for (int i = 0; i < 4; ++i)
                hours += (bits[i] == '1' ? bitTimeMap[i] : 0);
            for (int i = 4; i < bitTimeMap.size(); ++i)
                minutes += (bits[i] == '1' ? bitTimeMap[i] : 0);
            //std::cout << "hours: " << hours << " minutes: " << minutes << std::endl;
            if (hours < 12 && minutes < 60)            
            {
                string s = std::to_string(hours) + ":";
                if (minutes < 10)
                    s += "0" + std::to_string(minutes);
                else
                    s += std::to_string(minutes);
                result.push_back(s);
            }            
        }
        else  
        {
            for (int i = index; i < bits.size()-num+count+1; ++i)
            {
                bits[i] = '1';
                _timesRecursive(bits, i+1, count+1, num, result);
                bits[i] = '0';
            }
        }
    }
public:
    vector<string> readBinaryWatch2(int num) {
        if (num <= 0) return vector<string>({"0:00"});
        vector<string> result;
        if (num > 8) return result;

        vector<char> perBit(10);
        vector<int> bitTimeMap = {8,4,2,1,32,16,8,4,2,1};
        for (int i = 0; i < num; ++i)
            perBit[i] = '1';
        for (int i = num; i < perBit.size(); ++i)
            perBit[i] = '0';        
        std::sort(perBit.begin(), perBit.end());
        do {
            int hours = 0;
            int minutes = 0;
            //std::cout << std::string(perBit.begin(), perBit.end()) << " " << count << "\n";            
            for (int i = 0; i < 4; ++i)
                hours += (perBit[i] == '1' ? bitTimeMap[i] : 0);
            for (int i = 4; i < bitTimeMap.size(); ++i)
                minutes += (perBit[i] == '1' ? bitTimeMap[i] : 0);
            //std::cout << "hours: " << hours << " minutes: " << minutes << std::endl;
            if (hours < 12 && minutes < 60)            
            {
                string s = std::to_string(hours) + ":";
                if (minutes < 10)
                    s += "0" + std::to_string(minutes);
                else
                    s += std::to_string(minutes);
                
                result.push_back(s);
            }
        } while (std::next_permutation(perBit.begin(), perBit.end()));
        
        return result;
    }
};
void printResult(const std::vector<string>& strvector)
{
    std::cout << "[";
    for (auto& v : strvector)
        std::cout << v << " ";
    std::cout << "]" << std::endl;
}
int main() 
{
    Solution s;
    vector<string> res;
    std::cout << "method 1: \n";
    res = s.readBinaryWatch(1);
    printResult(res);

    res = s.readBinaryWatch(2);
    printResult(res);

    std::cout << std::endl;
    return 0;
}