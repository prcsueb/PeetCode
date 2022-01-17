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
    TreeNode *dfs(TreeNode* root) {
        if(!root)return root;
        TreeNode *leftTail = dfs(root->left);
        TreeNode *rightTail = dfs(root->right);
        if(root->left) {
            leftTail->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        return rightTail!=NULL?rightTail:leftTail!=NULL?leftTail:root;
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        dfs(root);
    }
};