

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;


/*
* Name: 从尾到头打印链表
* Description: 输入一个链表，从尾到头打印链表每个节点的值。
*
*/

struct ListNode {
        int val;
        struct ListNode *next;        
        ListNode(int x) 
            : val(x), next(NULL) {
       }
};


class Solution {
public:
    // 运行时间：4ms
    // 占用内存：468k
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head == NULL) return vector<int>();
        if (head->next == NULL) return  vector<int>(1, head->val);

        stack<int> stk;
        while (head)
        {
            stk.push(head->val);
            head = head->next;
        }

        vector<int> ret;
        while (!stk.empty())
        {
            ret.push_back(stk.top());
            stk.pop();
        }

        return ret;
    }
    // 运行时间：4ms
    // 占用内存：484k
    vector<int> printListFromTailToHead2(ListNode* head) {
        if (head == NULL) return vector<int>();
        if (head->next == NULL) return  vector<int>(1, head->val);

        vector<int> vec;
        while (head)
        {
            vec.push_back(head->val);
            head = head->next;
        }

        std::reverse(vec.begin(), vec.end());
        return vec;
    }

    vector<int> printListFromTailToHead3(ListNode* head) {
        if (head == NULL) return vector<int>();
        if (head->next == NULL) return  vector<int>(1, head->val);

        vector<int> vec;
        while (head)
        {
            //vec.push_front(head->val);
            vec.insert(vec.begin(),head->val);
            head = head->next;
        }

        //std::reverse(vec.begin(), vec.end());
        return vec;
    }
};

int main() 
{
    Solution s;
    ListNode ln(32);
    ListNode *cur = &ln;
    for (int i = 0; i < ln.val; ++i)
    {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    std::cout << "method 1: \n";

    vector<int> ret = s.printListFromTailToHead3(ln.next);
    for (auto &v : ret)
        std::cout << v << " ";
    std::cout << std::endl;
    return 0;
}
