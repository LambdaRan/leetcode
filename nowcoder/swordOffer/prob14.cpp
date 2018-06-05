

#include <iostream>
#include <algorithm>


using namespace std;

/*
* Name: 链表中倒数第k个结点
* Description: 输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    
       if (pListHead == NULL || k <= 0) return NULL;
        ListNode *fastPtr = pListHead;
        ListNode *slowPtr = pListHead;
        while (k && fastPtr)
        {
            fastPtr = fastPtr->next;
            --k;
        }
        if (k > 0) // 总数不够k个
        {
            return NULL;
        }

        while (fastPtr)
        {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        return slowPtr;
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
    std::cout << "method 1: \n";

    cout << "FindKthToTail(head->next, 1): " << (head.val - 1 + 1) << " --> " 
            << s.FindKthToTail(head.next, 1)->val << "\n";

    cout << "FindKthToTail(head->next, 13): " << (head.val - 13 + 1) << " --> " 
            << s.FindKthToTail(head.next, 13)->val << "\n";

    cout << "FindKthToTail(head->next, 20): " << (head.val - 20 + 1) << " --> " 
            << s.FindKthToTail(head.next, 20)->val << "\n";
            
    cout << "FindKthToTail(head->next, 30): " << (head.val - 30 + 1) << " --> " 
            << s.FindKthToTail(head.next, 30)->val << "\n";
    std::cout << std::endl;

    while(head.next)
    {
        ListNode* del = head.next;
        head.next = del->next;
        delete del;
        del = NULL;
    }
    head.next = NULL;
    return 0;
}
