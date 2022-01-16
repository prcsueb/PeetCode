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
    void helper(TreeNode* root, vector<vector<int>> &ans) {
        if(root==NULL)return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size=q.size();
            vector<int> smallAns;
            while(size > 0) {
                size--;
                TreeNode *front = q.front();
                q.pop();
                smallAns.push_back(front->val);
                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
            }
            ans.push_back(smallAns);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};