
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>

using namespace std;


/*
* Name: 141. Linked List Cycle
* Website: https://leetcode.com/problems/linked-list-cycle/description/
* Description: 
*
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    // 单链表判断是否有环
    // 使用两个指针:慢指针pSlow一次走一格,快指针pFast一次走两格,当快慢指针相遇时表明有环，否则无环
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* pSlow = head;
        ListNode* pFast = head->next;
        while (pFast && pFast->next)
        {
            if (pSlow->val == pFast->val)
                return true;
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        return false;
    }
};

int main() 
{
    string line;
    while (getline(cin, line)) {
        // ListNode* head = stringToListNode(line);
        // getline(cin, line);
        // int n = stringToInteger(line);
        
        // //ListNode* ret = Solution().removeNthFromEnd(head, n);

        // string out = listNodeToString(ret);
        //cout << out << endl;
    }
    return 0;
}
