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
    ListNode* sortList(ListNode* head) {
        int list_len = 0;
        for (ListNode *curr = head; curr; curr = curr->next) {
            list_len++;
        }
        ListNode *dummy = new ListNode(0, head);
        for (int len = 1; len < list_len; len *= 2) {
            ListNode *curr = dummy;
            while (curr->next) {
                ListNode *first = curr->next;
                ListNode *second = nextNthNode(first, len);
                ListNode *tail = nextNthNode(second, len);
                while (first || second) {
                    if (!second || (first && first->val < second->val)) {
                        curr->next = first;
                        first = first->next;
                    } else {
                        curr->next = second;
                        second = second->next;
                    }
                    curr = curr->next;
                }
                curr->next = tail;
            }
        }
        return dummy->next;
    }
private:
    ListNode *nextNthNode(ListNode *curr, int len) {
        while (curr && --len) {
            curr = curr->next;
        }
        if (!curr) {
            return nullptr;
        }
        ListNode *next = curr->next;
        curr->next = nullptr;
        return next;
    }
};
