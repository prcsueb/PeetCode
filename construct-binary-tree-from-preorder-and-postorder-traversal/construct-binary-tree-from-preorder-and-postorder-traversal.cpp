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
    TreeNode *helper(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd) {
        if((preStart > preEnd) || (postStart > postEnd)) {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd) {
            return root;
        }
        int idx = postStart;
        for(int i=0;i<postorder.size();i++) {
            if(postorder[i] == preorder[preStart + 1]) {
                idx = i;
                break;
            }
        }
        
        int leftCount = idx - postStart + 1;
        
        root->left = helper(preorder,postorder, preStart+1,preStart+leftCount,postStart,idx);   
        root->right = helper(preorder,postorder, preStart+leftCount+1,preEnd, idx+1, postEnd-1);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        if(n == 1) {
            return new TreeNode(preorder[0]);
        }
        
        return helper(preorder,postorder,0,n-1,0,n-1);
    }
};