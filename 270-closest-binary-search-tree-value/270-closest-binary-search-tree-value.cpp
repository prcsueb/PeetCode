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
    int closestValue(TreeNode* root, double target) {
        int ans=root->val;
        double gdist = DBL_MAX;
        TreeNode *curr=root;
        while(curr!=NULL) {
            if(abs(curr->val-target) < gdist) {
                ans=curr->val;
                gdist=abs(curr->val-target);
            }
            if(target < curr->val) {
                curr=curr->left;
            } else {
                curr=curr->right;
            }
        }
        
        return ans;
    }
};