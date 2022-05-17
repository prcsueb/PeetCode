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
    unordered_map<int,int> mp;
    TreeNode *helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if(ps > pe || is > ie) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[ps]);
        int key = mp[root->val];
        int leftCount = key-is;
        root->left=helper(preorder, inorder, ps+1,ps+leftCount,is,key-1);
        root->right=helper(preorder, inorder, ps+leftCount+1, pe, key+1, ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++) {
            mp[inorder[i]]=i;
        }
        TreeNode *ans = helper(preorder, inorder, 0, n-1, 0, n-1);        
        return ans;
    }
};