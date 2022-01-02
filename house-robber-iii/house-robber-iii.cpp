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
    class Pair{
      public:
        int incl;
        int excl;
        Pair(int incl, int excl) {
            this->incl = incl;
            this->excl = excl;
        }
    };
    
    Pair *helper(TreeNode *root) {
        if(root == NULL) {
            return new Pair(0, 0);
        }
        
        Pair *lp = helper(root->left);
        Pair *rp = helper(root->right);
        
        int inclMaxProfit = root->val + lp->excl + rp->excl;
        int exclMaxProfit = max(lp->incl, lp->excl) + max(rp->incl,rp->excl);
        
        return new Pair(inclMaxProfit, exclMaxProfit);
    }
    
    int rob(TreeNode* root) {
        Pair *ans = helper(root);
        return max(ans->incl, ans->excl);
    }
};