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
    ListNode* mergeKLists(vector<ListNode *>& lists) {
        auto cmp = [](ListNode *node1, ListNode *node2) {
            return node1->val > node2->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
        for (ListNode *node : lists) {
            if (node) {
                pq.push(node);
            }
        }
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while (!pq.empty()) {
            ListNode *smallest = pq.top();
            pq.pop();
            if (smallest->next) {
                pq.push(smallest->next);
            }
            curr->next = smallest;
            curr = curr->next;
        }
        if (curr) {
            curr->next = nullptr;    
        }
        return dummy->next;
    }
};
