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
    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);
    }
private:
    int sumNumbersHelper(TreeNode *root, int curr) {
        if (!root) {
            return 0;
        }
        int num = curr * 10 + root->val;
        if (!root->left && !root->right) {
            return num;
        }
        return sumNumbersHelper(root->left, num) + sumNumbersHelper(root->right, num);
    }
};
