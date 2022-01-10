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
        if(root==NULL) {
            return "N";
        }
        int val = root->val;
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(val) + " " + left + " " + right;
    }
    
    TreeNode *helper(stringstream &ss) {
        string s;
        ss >> s;
        if(s == "N") {
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(s));
        root->left = helper(ss);
        root->right = helper(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return helper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));