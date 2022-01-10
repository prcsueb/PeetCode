/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    void helper(Node *node) {
        if(node==NULL) {
            return;
        }
        
        helper(node->left);
        prev->right=node;
        node->left=prev;
        prev=node;
        
        helper(node->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return root;
        helper(root);
        Node *head = dummy->right;
        Node *tail = prev;
        //convert to circular
        head->left=tail;
        tail->right=head;
        return head;
    }
};