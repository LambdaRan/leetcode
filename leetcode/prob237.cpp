
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
* Name: 237. Delete Node in a Linked List
* Website: https://leetcode.com/problems/delete-node-in-a-linked-list/description/
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
    void deleteNode(ListNode* node) {
        if (!node) return;
        ListNode* curNext = node->next;
        node->val = curNext->val;
        node->next = curNext->next;
        delete curNext;
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
