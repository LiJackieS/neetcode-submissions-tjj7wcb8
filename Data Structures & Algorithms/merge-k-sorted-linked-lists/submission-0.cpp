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
        if (lists.size() == 0) {
            return nullptr;
        }
        while (lists.size() > 1) {
            vector<ListNode*> result;

            for (int i = 0; i < lists.size(); i+=2) {
                ListNode* list1 = lists[i];
                ListNode* list2 = (i + 1) < lists.size() ? lists[i + 1]: nullptr;
                result.push_back(mergeLists(list1, list2));
            }
            lists = result;
        }
        return lists[0];
    }
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* head = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                head->next = list1;
                list1 = list1->next;
            }
            else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        head->next = list1 ? list1 : list2;

        return dummy.next;

    }
};
