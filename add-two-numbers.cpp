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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int sum;
            if (l1 == nullptr && l2 == nullptr) {
                break;
            } else if (l1 == nullptr) {
                sum = l2->val + carry;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                sum = l1->val + carry;
                l1 = l1->next;
            } else {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            curr = curr->next;
        }
        if (carry) {
            curr->next = new ListNode(1);
        }
        return dummy->next;
    }
};

// Time: O(n)
// Space: O(1)
