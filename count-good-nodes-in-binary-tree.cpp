/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return goodNodesHelper(root, root->val);
    }
private:
    int goodNodesHelper(TreeNode *root, int maximum) {
        if (!root) {
            return 0;
        }
        maximum = max(maximum, root->val);
        return (root->val == maximum) + goodNodesHelper(root->left, maximum) + goodNodesHelper(root->right, maximum);
    }
};

// Time: O(n)
// Space: O(n)
