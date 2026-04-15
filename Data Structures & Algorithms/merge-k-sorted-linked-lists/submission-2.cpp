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
        if (lists.empty()) {
            return nullptr;
        }
        for (int i = 1; i < lists.size(); i++) {
            lists[i] = merge(lists[i], lists[i-1]);
        }
        return lists.back();
    }

    ListNode* merge(ListNode* node1, ListNode* node2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while (node1 && node2) {
            if (node1->val < node2->val) {
                head->next = node1;
                node1 = node1->next;
            }
            else {
                head->next = node2;
                node2 = node2->next;
            }
            head = head->next;
        }
        if (node1) {
            head->next = node1;
        }
        if (node2) {
            head->next = node2;
        }
        return dummy->next;
    }
};
