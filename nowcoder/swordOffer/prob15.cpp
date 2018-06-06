
#include <iostream>
#include <algorithm>


using namespace std;

/*
* Name: 反转链表
* Description: 输入一个链表，反转链表后，输出链表的所有元素。 
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
    ListNode* ReverseList(ListNode* pHead) {

        if (pHead == NULL) return NULL;

        ListNode head(0);
        ListNode *cur = NULL;
        while(pHead)
        {
            cur = pHead;
            pHead = pHead->next;
            cur->next = head.next;
            head.next = cur;
        }
        cur = NULL;
        return head.next;
    }
};

int main() 
{
    Solution s;
    ListNode head(32);
    for (int i = head.val; i != 0 ; --i)
    {   
        ListNode* node = new ListNode(i);
        node->next = head.next;
        head.next = node;
    }
    std::cout << "before: \n";
    ListNode* pri = head.next;
    while (pri)
    {
        std::cout << pri->val << " ";
        pri = pri->next;
    }
    std::cout << "\n";

    head.next = s.ReverseList(head.next);

    std::cout << "after:\n";
    while(head.next)
    {
        ListNode* del = head.next;
        head.next = del->next;
        std::cout << del->val << " ";
        delete del;
        del = NULL;
    }
    head.next = NULL;

    std::cout << std::endl;
    return 0;
}