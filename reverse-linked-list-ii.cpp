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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        ListNode *new_head = prev->next, *new_tail = new_head->next;
        for (int i = left; i < right; i++) {
            ListNode *next = new_head->next;
            new_head->next = new_tail;
            new_tail = new_head;
            new_head = next;
        }
        prev->next->next = new_head->next;
        new_head->next = new_tail;
        prev->next = new_head;
        return dummy->next;
    }
};
