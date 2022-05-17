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
    vector<int> list;
    void helper(TreeNode *root, int num) {
        if(root==NULL) return;
        if(!root->left && !root->right) {
            num = num*10+root->val;
            list.push_back(num);
            return;
        }
        helper(root->left,num*10+root->val);
        helper(root->right,num*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        int sum= 0;
        helper(root, 0);
        for(auto &x:list) {
            sum+=x;
        }
        return sum;
    }
};