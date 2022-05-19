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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    
    void insertLeft() {
        TreeNode *top = stk.top();
        while(top->left != NULL) {
            top=top->left;
            stk.push(top);
        }
    }
    
    BSTIterator(TreeNode* root) {
        stk.push(root);
        insertLeft();
    }
    
    int next() {
        int nextVal = 0;
        if(hasNext()) {
            TreeNode *top = stk.top();
            stk.pop();
            nextVal = top->val;
            if(top->right) {
                stk.push(top->right);
                insertLeft();
            }
        } else {
            stk.pop();
            nextVal = -1;
        }
        return nextVal;
    }
    
    bool hasNext() {
        return stk.size()>0?true:false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */