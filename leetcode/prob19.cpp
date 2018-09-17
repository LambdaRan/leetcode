
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
* Name: 19. Remove Nth Node From End of List
* Description: Given a linked list, remove the n-th node from the end of list and return its head.
* 
* Example:
* Given linked list: 1->2->3->4->5, and n = 2.
* After removing the second node from the end, the linked list becomes 1->2->3->5.
* Note:
* Given n will always be valid.
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
    // 思路： 利用两个指针，快指针慢指针，快指针先移动n步，然后慢指针指向头节点，
    // 这样当快指针走到链表尾部时，慢指针正好指向要删除节点之前， 删除节点即可。
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        ListNode root(0);
        root.next = head;
        ListNode* fast = head;
        while (n--)
            fast = fast->next;

        ListNode* slow = &root;

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* cur = slow->next;
        slow->next = slow->next->next;
        delete cur;
        return root.next;
        
        // ListNode* fast = head;
        // while (n-- && fast) // 快指针先移动n步
        //     fast = fast->next;
        // // 链表总长度不够n
        // if (n > 0)  return head; 
        // ListNode* slow = head;
        // if (fast) // 处理一个节点的情况
        // {
        //     while (fast->next)
        //     {
        //         fast = fast->next;
        //         slow = slow->next;
        //     }
        // }
        // // 处理要删除的节点是头节点时
        // if (slow == head && !fast) 
        // {
        //     head = head->next;
        //     delete slow;
        // }
        // else  
        // {
        //     ListNode* cur = slow->next;
        //     slow->next = slow->next->next;
        //     delete cur;
        // }
        //return head;
    }
};
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        ListNode* ret = Solution().removeNthFromEnd(head, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}