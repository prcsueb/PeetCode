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
    vector<vector<int>> list;
    void helper(TreeNode *root, int sum, int target, vector<int> rootToLeafPath) {
        if(root==NULL) return;
        if(!root->left && !root->right && sum+root->val == target) {
            rootToLeafPath.push_back(root->val);
            list.push_back(rootToLeafPath);
            return;
        }
        rootToLeafPath.push_back(root->val);
        helper(root->left,sum+root->val,target,rootToLeafPath);
        helper(root->right,sum+root->val,target,rootToLeafPath);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> rootToPath;
        helper(root, 0, targetSum, rootToPath);
        return list;
    }
};