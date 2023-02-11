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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = dummy, *slow = dummy;
        while (--k) {
            fast = fast->next;
        }
        ListNode *lprev = fast, *lcurr = lprev->next;
        fast = fast->next;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *rprev = slow, *rcurr = rprev->next;
        swap(lprev->next, rprev->next);
        swap(lcurr->next, rcurr->next);
        return dummy->next;
    }
};
