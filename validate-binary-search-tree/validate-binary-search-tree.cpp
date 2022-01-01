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
    TreeNode *prev;
    bool helper(TreeNode *node) {
        if(node == NULL) {
            return true;
        }
    
        bool left = helper(node->left);
        
        if(prev!=NULL && prev->val>=node->val) {
            return false;
        }
        
        prev= node;
        
        bool right = helper(node->right);
        
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return helper(root);
    }
};