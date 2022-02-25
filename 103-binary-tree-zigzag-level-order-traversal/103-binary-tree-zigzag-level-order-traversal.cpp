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
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=true;
        int lvl=2;
        ans.push_back({root->val});
        while(!q.empty()) {
            int size=q.size();
            vector<int> smallAns;
            while(size > 0) {
                size--;
                TreeNode *front = q.front();
                q.pop();
                cout << lvl << endl;
                if(front->left) {
                    q.push(front->left);
                    smallAns.push_back(front->left->val);
                }
                if(front->right) {
                    q.push(front->right);
                    smallAns.push_back(front->right->val);
                }
            }
            if(smallAns.size()>0) {
                if(lvl%2==0) {
                    reverse(smallAns.begin(),smallAns.end());
                }
                ans.push_back(smallAns);
            }
            lvl++;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        helper(root, ans);
        return ans;
    }
};