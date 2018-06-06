
#include <iostream>
#include <assert.h>

using namespace std;

/*
* Name: 合并两个排序的链表
* Description: 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*
*/
struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) 
        : val(x), next(NULL) 
    {}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode newHead(0);
        ListNode* newCur = &newHead;
        while (pHead1 && pHead2)
        {
            ListNode *cur = pHead1;
            if (pHead1->val <= pHead2->val)
            {
                pHead1 = pHead1->next;
            }
            else 
            {
                cur = pHead2;
                pHead2 = pHead2->next;
            }

            newCur->next = cur;
            newCur = newCur->next;
            cur = NULL;
        }

        if (pHead1)
        {
            newCur->next = pHead1;
        }

        if (pHead2)
        {
            newCur->next = pHead2;
        }

        return newHead.next;
    }
};

void printList(const char *placeholder, ListNode *pList)
{
    if (pList == NULL) return;
    std::cout << "\n" << placeholder << ":";
    ListNode* cur = pList;
    while (cur)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}
ListNode* createList(int size, int step)
{
    assert(size > 0);
    ListNode* newList = NULL;
    for (int i = size; i >= 0 ; i -= step)
    {   
        ListNode* node = new ListNode(i);
        node->next = newList;
        newList = node;
    } 
    return newList;   
}
void freeList(ListNode *pList)
{
    assert(pList != NULL);
    while(pList)
    {
        ListNode* del = pList;
        pList = del->next;
        delete del;
    }   
}
int main() 
{
    Solution s;
    ListNode head1(32);
    head1.next = createList(head1.val, 2);
    printList("head1", head1.next);

    ListNode head2(64);
    head2.next = createList(head2.val, 3);
    printList("head2", head2.next);

    ListNode *ret = s.Merge(head1.next, head2.next);
    printList("merge", ret);

    freeList(ret);
    head1.next = NULL;
    head2.next = NULL;
    ret = NULL;

    return 0;
}