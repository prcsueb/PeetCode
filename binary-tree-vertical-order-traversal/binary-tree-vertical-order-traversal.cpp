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
    map<int,vector<int>> mp; //col, vector of values corrsponding to particular column
    void helper(TreeNode *root) {
        if(root == NULL) {
            return ;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int minn = INT_MAX;
        int maxx = INT_MIN;
        
        while(!q.empty()) {
            int size = q.size();
            while(size-- > 0) {
                size--;
                
                pair front = q.front();
                q.pop();
                
                minn = min(minn, front.second);
                maxx = min(maxx, front.second);
                
                if(front.first->left) {
                    q.push({front.first->left, front.second-1});
                }
                
                if(front.first->right) {
                    q.push({front.first->right, front.second+1});
                }
                
                mp[front.second].push_back(front.first->val);
            }
        }
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        helper(root);
        vector<vector<int>> ans;
        for(auto x : mp) {
            vector<int> a;
            for(auto f : x.second) {
                a.push_back(f);
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};