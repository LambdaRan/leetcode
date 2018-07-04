
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
* Name: 两个链表的第一个公共结点
* Description: 输入两个链表，找出它们的第一个公共结点。
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) return NULL;

        int oneLength = 0;
        ListNode* oneCurPtr = pHead1;
        while (oneCurPtr)
        {
            ++oneLength;
            oneCurPtr = oneCurPtr->next;
        }

        int twoLength = 0;
        ListNode* twoCurPtr = pHead2;
        while (twoCurPtr)
        { 
            ++twoLength;
            twoCurPtr = twoCurPtr->next;
        }

        int dif = oneLength > twoLength ? oneLength-twoLength : twoLength-oneLength;
        oneCurPtr = pHead1;
        twoCurPtr = pHead2;
        if (oneLength > twoLength)
        {
            for (int i = 0; i < dif; ++i)
                oneCurPtr = oneCurPtr->next;
        }
        else  
        {
            for (int i = 0; i < dif; ++i)
                twoCurPtr = twoCurPtr->next;            
        }
        while (oneCurPtr != NULL &&
                twoCurPtr != NULL &&
                oneCurPtr != twoCurPtr)
        {
            oneCurPtr = oneCurPtr->next;
            twoCurPtr = twoCurPtr->next;
        }

        return oneCurPtr;
    }
    ListNode* FindFirstCommonNode_withSet( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) return NULL;

        std::unordered_set<int> headOneSet;
        for (ListNode* oneCurPtr = pHead1; 
            oneCurPtr != NULL; 
            oneCurPtr = oneCurPtr->next)
        {
            headOneSet.insert(oneCurPtr->val);
        }

        for (ListNode* twoCurPtr = pHead2; 
            twoCurPtr != NULL; 
            twoCurPtr = twoCurPtr->next)
        {
            std::unordered_set<int>::iterator ret = headOneSet.find(twoCurPtr->val);
            if (ret != headOneSet.end())
                return twoCurPtr;
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
