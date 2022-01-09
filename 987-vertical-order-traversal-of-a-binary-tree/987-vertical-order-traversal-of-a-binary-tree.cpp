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
    map<int,map<int,multiset<int>>> mp;
    void helper(TreeNode* root,int col,int row) {
        if(!root)return;
        
        mp[col][row].insert(root->val);
        helper(root->left,col-1,row+1);
        helper(root->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root,0,0);
        vector<vector<int>> ans;
        for(auto m1:mp) {
            vector<int> a;
            for(auto m2:m1.second) {
                for(auto x:m2.second) {
                    a.push_back(x);
                }
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};