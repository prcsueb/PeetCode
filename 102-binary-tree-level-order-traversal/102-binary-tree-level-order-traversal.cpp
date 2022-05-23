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
        if(root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {            
            int size = q.size();
            vector<int> helperVector;
            while(size--) {
                TreeNode *front = q.front();
                helperVector.push_back(front->val);
                q.pop();
                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
            }
            ans.push_back(helperVector);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, ans);
        return ans;
    }
};