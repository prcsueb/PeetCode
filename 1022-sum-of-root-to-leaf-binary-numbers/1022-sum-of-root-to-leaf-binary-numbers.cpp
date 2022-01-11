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
    // 100-0*(2,0)+0*(2,1)+1(2,2)=4
    int getDecimal(string num) {
        int n=0;
        int p=0;
        for(int i=num.length()-1;i>=0;i--) {
            n += (num[i]-'0')*pow(2,p);
            p++;
        }
        cout << n << endl;
        return n;
    }
    int sum=0;
    void helper(TreeNode* root,string num) {
        if(root->left==NULL && root->right==NULL) {
            num+=to_string(root->val);
            sum += getDecimal(num);
            return;
        }
        
        if(root->left!=NULL)helper(root->left,num+to_string(root->val));
        if(root->right!=NULL)helper(root->right,num+to_string(root->val));
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL)return 0;
        string num="";
        helper(root,num);
        return sum;
    }
};