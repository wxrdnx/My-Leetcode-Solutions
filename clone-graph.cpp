
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node *, Node *> cache;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        return dfs(node);
    }
private:
    Node *dfs(Node *node) {
        if (cache.find(node) != cache.end()) {
            return cache[node];
        }
        Node *clone = new Node(node->val);
        cache[node] = clone;
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }
        return clone;
    }
};

// Time: O(V + E)
// Space: O(V + E)
