/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serialize_helper(root, result);
        result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss{data};
        return deserialize_helper(ss);
    }
private:

    void serialize_helper(TreeNode *curr, string& str) {
        if (!curr) {
            str += ',';
            return;
        }
        str += to_string(curr->val);
        str += ',';
        serialize_helper(curr->left, str);
        serialize_helper(curr->right, str);
    }
    TreeNode* deserialize_helper(stringstream& ss) {
        TreeNode *curr = nullptr;
        string val;
        getline(ss, val, ',');
        if (val.length() > 0) {
            curr = new TreeNode(stoi(val));
            curr->left = deserialize_helper(ss);
            curr->right = deserialize_helper(ss);
        }
        return curr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
