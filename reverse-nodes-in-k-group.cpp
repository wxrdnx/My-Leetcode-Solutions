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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *test = dummy, *tail = dummy;
        while (test) {
            for (int i = 0; i < k && test; i++) {
                test = test->next;
            }
            if (test) {
                ListNode *prev = tail->next, *curr = prev->next;
                for (int i = 1; i < k; i++) {
                    ListNode *next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                ListNode *next = tail->next;
                next->next = curr;
                tail->next = prev;
                test = tail = next;
            }
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        for (int i = 0; i < k - 1 && curr; i++) {
            curr = curr->next;
        }
        if (!curr) {
            return head;
        }
        ListNode *new_head = reverseKGroup(curr->next, k);
        curr = head;
        for (int i = 0; i < k; i++) {
            ListNode *next = curr->next;
            curr->next = new_head;
            new_head = curr;
            curr = next;
        }
        return new_head;
    }
};
