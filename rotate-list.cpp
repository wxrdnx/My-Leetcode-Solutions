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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        int len = 1;
        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = (len - k % len) % len;
        while (k--) {
            tail = tail->next;
            head = head->next;
        }
        tail->next = nullptr;
        return head;
    }
};

// Time: O(n)
// Space: O(1)
