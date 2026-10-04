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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1 -> 2 -> 4
        // 1 -> 3 -> 5
        if (!list1 && !list2) {
            return nullptr;
        }
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }

        ListNode* head = nullptr;
        if (list1->val > list2->val) {
            head = list2;
            list2 = list2->next;
        }
        else {
            head = list1;
            list1 = list1->next;
        }
        auto iter{ head };

        while (list1 && list2) {
            if (list1->val > list2->val) {
                iter->next = list2;
                list2 = list2->next;
            }
            else {
                iter->next = list1;
                list1 = list1->next;
            }
            iter = iter->next;
        }

        if (list1) {
            iter->next = list1;
        }
        if (list2) {
            iter->next = list2;
        }
        return head;
    }
};
