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
    map<int,map<int,vector<int>>> mp;
    void dfs(TreeNode* root,int col,int row) {
        if(root == NULL) {
            return;
        }
        
        mp[col][row].push_back(root->val);
        dfs(root->left,col-1,row+1);
        dfs(root->right,col+1,row+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,0);
        for(auto it=mp.begin();it!=mp.end();it++) {
            auto m = it->second;
            vector<int> a;
            for(auto t=m.begin();t!=m.end();t++) {
                vector<int> vt = t->second;
                for(auto x : vt) {
                    a.push_back(x);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};