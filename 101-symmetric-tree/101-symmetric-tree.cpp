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
    bool helper(TreeNode *leftRoot, TreeNode* rightRoot) {
        if(leftRoot==NULL && rightRoot==NULL) {
            return true;
        }
        if(leftRoot==NULL || rightRoot==NULL) {
            return false;
        }
        if(leftRoot->val != rightRoot->val) {
            return false;
        }
        return helper(leftRoot->right,rightRoot->left) && helper(leftRoot->left,rightRoot->right);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};