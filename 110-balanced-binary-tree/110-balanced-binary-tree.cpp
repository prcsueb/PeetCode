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
    bool ans = true;
    int height(TreeNode* root) {
        if(root==NULL) {
            return -1;
        }
        int left = height(root->left);
        int right = height(root->right);
        ans = ans && abs(left-right) <= 1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }
};