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
    TreeNode* helper(vector<int>& preorder,int &idx,int low,int high) {
        if(idx == preorder.size() || preorder[idx] < low || preorder[idx] > high) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[idx]);
        idx++;
        
        root->left = helper(preorder,idx,low,root->val-1);
        root->right = helper(preorder,idx,root->val+1,high);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return helper(preorder,idx,0,1001);
    }
};