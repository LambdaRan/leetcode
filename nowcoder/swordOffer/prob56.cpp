
#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

/*
* Name: 删除链表中重复的结点
* Description: 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
* 重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL) return NULL;
        if (pHead->next == NULL) return pHead;

        ListNode rootNode = ListNode(0); 
        rootNode.next = pHead;

        ListNode* prePtr = &rootNode;
        ListNode* slowPtr = prePtr->next;
        ListNode* fastPtr = slowPtr->next;
        while (prePtr->next)
        {
            slowPtr = prePtr->next;
            if (slowPtr->next)
                fastPtr = slowPtr->next;
            else 
                break;
            // 找到总共多少个重复的元素
            while (fastPtr != NULL && slowPtr->val == fastPtr->val)
                fastPtr = fastPtr->next;
            
            //std::cout << "slowPtr: " << slowPtr->val << " fastPtr: " << fastPtr->val << std::endl;
            // 有重复节点, 重复元素为 slowPtr ~ fastPtr
            if (slowPtr->next != fastPtr)
            {
                while (prePtr->next != fastPtr)
                {
                    slowPtr = prePtr->next;
                    prePtr->next = slowPtr->next;
                    delete slowPtr;
                }
            }
            else  
            {
                prePtr = prePtr->next;
            }
            //std::cout << "prePtr: " << prePtr->val << std::endl;
        }
        pHead = rootNode.next;
        return pHead;
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
ListNode* createList(vector<int>& data)
{
    assert(data.size() > 0);
    ListNode* newList = NULL;
    for (int i = 0; i < data.size(); ++i)
    {   
        ListNode* node = new ListNode(data[i]);
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
    std::vector<int> vec1 = {1,2,3,3,3,4,4,5};
    ListNode* list1 = createList(vec1);
    printList("head1", list1);

    ListNode* ret = list1;
    s.deleteDuplication(ret);
    printList("after:", ret);
    freeList(ret);

    return 0;
}
