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
    void helper(TreeNode* root, vector<int> &ans) {
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            bool isFront = true;
            while(size--) {
                TreeNode *front = q.front();
                if(isFront) {
                    ans.push_back(front->val);
                    isFront=false;
                }
                if(front->right) {
                    q.push(front->right);
                }
                if(front->left) {
                    q.push(front->left);
                }
                q.pop();
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};