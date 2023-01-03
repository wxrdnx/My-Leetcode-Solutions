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
    void reorderList(ListNode* head) {
        deque<ListNode *> dq;
        for (ListNode *curr = head->next; curr; curr = curr->next) {
            dq.push_back(curr);
        }
        ListNode *curr = head;
        for (int i = 0; !dq.empty(); i++, curr = curr->next) {
            if (i % 2 == 0) {
                curr->next = dq.back();
                dq.pop_back();
            } else {
                curr->next = dq.front();
                dq.pop_front();
            }
        }
        curr->next = nullptr;
    }
};

// Time: O(n)
// Space: O(n)

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head->next) {
            return;
        }
        ListNode *dummy = new ListNode(0, head), *slow = dummy, *fast = dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *curr = slow->next, *prev = nullptr;
        while (curr && curr->next) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        slow->next = nullptr;
        while (head && curr) {
            ListNode *head_next = head->next, *curr_next = curr->next;
            head->next = curr;
            curr->next = head_next;
            head = head_next;
            curr = curr_next;
        }
    }
};

// Time: O(n)
// Space: O(1)
