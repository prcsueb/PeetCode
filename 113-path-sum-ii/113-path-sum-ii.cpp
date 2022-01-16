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
    void helper(TreeNode* root, int targetSum, vector<int> list, vector<vector<int>> &ans,int sum) {
        if(root==NULL) {
            return;
        }
        
        list.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL && targetSum == sum+root->val) {
            cout << sum << endl;
            ans.push_back(list);
            return;
        }
        
        helper(root->left,targetSum,list,ans,sum+root->val);
        helper(root->right,targetSum,list,ans,sum+root->val);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> list;
        helper(root,targetSum,list,ans,0);
        return ans;
    }
};