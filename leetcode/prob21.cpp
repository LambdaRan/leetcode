
// https://leetcode.com/problems/merge-two-sorted-lists/description/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 21. Merge Two Sorted Lists
* Description: 
* Merge two sorted linked lists and return it as a new list. The new list should be made 
* by splicing together the nodes of the first two lists.
* 
* Example:
* Input: 1->2->4, 1->3->4
* Output: 1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 **/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode head(0);
        ListNode* tail = &head;
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else  
            {
               tail->next = list2;
               list2 = list2->next; 
            }
            tail = tail->next;
        }
        // if (list1 != NULL)
        //     tail->next = list1;
        // if (list2 != NULL)
        //     tail->next = list2;
        tail->next = list1 ? list1 : list2;
        return head.next;
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
