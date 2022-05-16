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
    TreeNode *getRight(TreeNode* ln, TreeNode* c) {
        while(ln->right != NULL && ln->right!=c) {
            ln=ln->right;
        }
        return ln;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        TreeNode* c = root;
        vector<int> ans;
        while(c != NULL) {
            TreeNode *ln = c->left;
            if(c->left == NULL) {
                ans.push_back(c->val);
                c=c->right;
            } else {
                TreeNode *rightMost = getRight(ln,c);
                if(rightMost->right == NULL) {
                    rightMost->right = c;
                    c = c->left;
                } else if(rightMost -> right == c) {
                    rightMost->right = NULL;
                    ans.push_back(c->val);
                    c=c->right;
                }
            }
        }
        return ans;
    }
};