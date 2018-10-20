
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
* Name: 234. Palindrome Linked List
* Website: https://leetcode.com/problems/palindrome-linked-list/description/
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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        int size = 0;
        ListNode* cur = head;
        while (cur) // 统计链表长度
        {
            ++size;
            cur = cur->next;
        }
        int mid = size / 2;
        
        ListNode root(0);
        ListNode* pHead = head;
        // 利用头插法翻转前半截链表
        while (mid)
        {
            cur = pHead;
            pHead = pHead->next;
            cur->next = root.next;
            root.next = cur;
            --mid;
        }
        // 保存后半截链表
        //head = pHead;
        
        if (size % 2 == 1) pHead = pHead->next;
        cur = root.next;
        while (cur && pHead)
        {
            if (cur->val != pHead->val)
                return false;
            cur = cur->next;
            pHead = pHead->next;
        }
        return cur == nullptr && pHead == nullptr;
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
