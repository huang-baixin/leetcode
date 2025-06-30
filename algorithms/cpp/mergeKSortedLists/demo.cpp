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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1,ListNode* list2) {
        if (!list1) { return list2; }
        if (!list2) { return list1; }

        ListNode dummy(0, nullptr);
        ListNode* prev = &dummy; 
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        while (cur1 && cur2) {
            if (cur2->val <= cur1->val) {
                prev->next = cur2;
                cur2 = cur2->next;
            } else {
                prev->next = cur1;
                cur1 = cur1->next;
            }
            prev = prev->next;
        }

        prev->next = cur1 ? cur1 : cur2;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.empty()) {
            return nullptr;
        }
        
        int len = lists.size();
        while(len > 1) {
            int mid = (len + 1) / 2; // + 1  奇数长度时，最后一个元素也能合并，最中间的放到下一轮(作为下一轮的最后一个元：
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + mid]);
            }
            len = mid;
        }
        return lists[0];
        
    }
};