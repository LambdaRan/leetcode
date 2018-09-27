
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
* Name: 83.Remove Duplicates from Sorted List
* Website: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
* Description: 
*
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == nullptr) return head;
        ListNode* pSlow = head;
        ListNode* pFast = pSlow->next;
        while(pFast)
        {
            if (pFast->val == pSlow->val)
            {
                ListNode* cur = pFast;
                pSlow->next = cur->next;
                delete cur;
            }
            else  
            {
                pSlow = pSlow->next;
            }
            pFast = pSlow->next;
        }
        return head;
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
