
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

// https://www.nowcoder.com/questionTerminal/253d2c59ec3e4bc68da16833f79a38e4
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL) 
            return NULL;
        // 判断是否有环
        ListNode* pFast = pHead->next->next;
        ListNode* pSlow = pHead->next; // 为什么是pHead->next而不是pHead
        while (pFast != pSlow)
        {
            if (pFast->next && pFast->next->next)
            {
                pFast = pFast->next->next;
                pSlow = pSlow->next;
            }
            else  
                return NULL;
        }
        // 到达此处，说明链表存在环，此时 pFast = pSlow
        pFast = pHead;
        while (pFast != pSlow)
        {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }

    ListNode* EntryNodeOfLoop_v1(ListNode* pHead)
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
