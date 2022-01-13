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
**/
class Solution {
public:
    int dia=0;
    int helper(TreeNode* root) {
        //faith : let's say we are standing on 2
        //left ni hight = 0, right ni height = 0, diameter = leftheight+rightheight+2
        //return height of 2 which is max(leftheight, rightheight) + 1
        if(root==NULL)return -1;
        int leftHeight = helper(root->left);
        int rightHeight = helper(root->right);
        dia=max(dia,leftHeight+rightHeight+2);
        return max(leftHeight,rightHeight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int val = helper(root);
        return dia;
    }
};