#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <

#include "gtest/gtest.h"

using namespace std;

// Name: 23. Merge k Sorted Lists
// Website: https://leetcode.com/problems/merge-k-sorted-lists/
// Description:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::multimap<int, ListNode*> all_node_sorted_with_val;
        for (ListNode* list : lists) {
            ListNode* cur = list;
            while(cur) {
                all_node_sorted_with_val.insert(std::make_pair(cur->val, cur));
                cur = cur->next;
            }
        }
        ListNode result;
        ListNode* head = &result;
        for (auto iter = all_node_sorted_with_val.begin();
             iter != all_node_sorted_with_val.end(); ++iter) {
            head->next = iter->second;
            head = iter->second;
        }
        return result.next;
    }

    ListNode* mergeKLists_v2(std::vector<ListNode*>& lists) {
        auto key_comp = [](const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(key_comp)> kq(key_comp);

        for (ListNode* list : lists) {
            if (list) {
                kq.push(list);
            }
        }

        ListNode result;
        ListNode* head = &result;
        while (!kq.empty()) {
            ListNode* node = kq.top(); kq.pop();
            head->next = node;
            head = head->next;

            if (node->next) {
                kq.push(node->next);
            }
        }
        return result.next;
    }

    ListNode* merge2List(ListNode* l, ListNode* r) {
        ListNode result;
        ListNode* head = &result;
        while (l && r) {
            if (l->val <= r->val) {
                head->next = l;
                l = l->next;
            } else {
                head->next = r;
                r = r->next;
            }
            head = head->next;
        }
        if (l) {
            head->next = l;
        }
        if (r) {
            head->next = r;
        }
        return result.next;
    }
    ListNode* mergeKLists_v3(std::vector<ListNode*>& lists) {
        int amount = lists.size();
        int interval = 1;
        while (interval < amount) {
            int end = amount - interval;
            int step = interval * 2;
            for (int i = 0; i < end; i += step) {
                lists[i] = merge2List(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return amount > 0 ? lists[0] : nullptr;
    }
};

Solution solu;

// TEST(Fuction, one) {}