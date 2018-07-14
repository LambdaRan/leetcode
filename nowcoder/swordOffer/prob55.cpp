
#include <iostream>
#include <algorithm>

#include <unordered_set>

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
        if (pHead == NULL) return NULL;
        std::unordered_set<ListNode*> visitedNodeSet_;
        ListNode* cur = pHead;
        while (cur)
        {
            if (visitedNodeSet_.find(cur) != visitedNodeSet_.end())
                return cur;
            else  
                visitedNodeSet_.insert(cur);
            cur = cur->next;
        }
        return NULL;
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
