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
    vector<int> allVals;
    void helper(TreeNode* root) {
        if(root==NULL) {
            return;
        }
        allVals.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
    class Node {
        public:
        double arrValMinustarget;
        int idx;
        Node(double a, int i) {
            arrValMinustarget = a;
            idx = i;
        }
    };
    class Compare {
    public:
        bool operator()(Node a, Node b)
        {
            return a.arrValMinustarget>b.arrValMinustarget;
        }
    };
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        helper(root);
        sort(allVals.begin(), allVals.end());
        priority_queue<Node, vector<Node>, Compare> pq;
        for(auto &x:allVals) {
            pq.push(Node(abs(x-target), x));
        }        
        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().idx);
            pq.pop();
        }
        return ans;
    }
};