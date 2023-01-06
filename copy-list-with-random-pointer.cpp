/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node *curr = head;
        while (curr) {
            Node *next = curr->next;
            curr->next = new Node(curr->val);
            curr = curr->next->next = next;
        }
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node *new_head = curr->next;
        while (curr->next->next) {
            Node *next2 = curr->next->next;
            curr->next->next = next2->next;
            curr->next = next2;
            curr = next2;
        }
        curr->next = nullptr;
        return new_head;
    }
};
