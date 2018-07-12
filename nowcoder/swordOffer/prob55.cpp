
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 链表中环的入口结点
* Description: 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*
*/
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) 
        : val(x), next(NULL) 
    {}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {

    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
