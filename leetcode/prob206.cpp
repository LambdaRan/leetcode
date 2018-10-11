
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
* Name: 206. Reverse Linked List
* Website: https://leetcode.com/problems/reverse-linked-list/description/
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            ListNode* curNext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = curNext;
        }
        return prev;
    }
    ListNode* reverseList_v1(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(0);
        ListNode* cur = nullptr;
        while (head)
        {
            cur = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = cur;
        }
        return dummy.next;
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
