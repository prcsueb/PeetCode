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
    TreeNode *prev, *first, *second;
    void helper(TreeNode *node) {
        if(node == NULL) {
            return;
        }
        
        helper(node->left);
        if(prev!=NULL && prev->val >= node->val) {
            if(second == NULL) {
                first = prev;
            }
            second = node;
        }
        
        prev = node;
        helper(node->right);
        
        return;
    }
    void recoverTree(TreeNode* root) {
        prev = first = second = NULL;
        helper(root);
        int x = second->val;
        second->val = first->val;
        first->val = x;
    }
};