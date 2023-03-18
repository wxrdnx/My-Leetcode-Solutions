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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        binaryTreePaths(result, root, {});
        return result;
    }
private:
    void binaryTreePaths(vector<string>& result, TreeNode *root, vector<string>&& path) {
        if (!root) {
            return;
        }
        path.push_back(to_string(root->val));
        if (!root->left && !root->right) {
            ostringstream oss;
            copy(path.begin(), prev(path.end()), ostream_iterator<string>(oss, "->"));
            oss << *prev(path.end());
            result.push_back(oss.str());
        } else {
            binaryTreePaths(result, root->left, move(path));
            binaryTreePaths(result, root->right, move(path));
        }
        path.pop_back();
    }
};
