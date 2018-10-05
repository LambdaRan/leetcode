
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
* Name: 160. Intersection of Two Linked Lists
* Website: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
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
    // 分别遍历两个链表,得到headA链表长度LA,headB链表的长度LB
    // 链表长的先走abs(LA-LB)长度,然后一起走，查看是否有相同的元素
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA && !headB) return nullptr;
        if (headA && headB)
        {
            ListNode* curA = headA;
            int lenA = 0;
            while (curA)
            {
                ++lenA;
                curA = curA->next;
            }

            ListNode* curB = headB;
            int lenB = 0;
            while (curB)
            {
                ++lenB;
                curB = curB->next;
            }
            curA = headA;
            curB = headB;
            int diff = 0;
            if (lenA < lenB)
            {
                diff = lenB - lenA;
                while (diff--)
                    curB = curB->next;
            }
            else  
            {
                diff = lenA - lenB;
                while (diff--)
                    curA = curA->next;
            }
            while (curA && curB && (curA->val != curB->val))
            {
                curA = curA->next;
                curB = curB->next;
            }
            return curA;
        }
        return nullptr;
    }
    // 方法二： 使用hash
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
