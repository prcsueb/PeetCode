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
    Node *prev, *node, *head, *tail;
    void helper(Node *node) {
        if(node == NULL) {
            return;
        }
        helper(node->left);
        
        if(prev == NULL) {
            head = node;
        } else {
            prev->right  =node;
            node -> left = prev;
        }
        prev = node;
        
        helper(node->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) {
            return root;
        }
        prev = node = head = tail = NULL;
        helper(root);
        tail = prev; //last previous is tail and first prev is head
        
        //connect tail and head for circular thing
        head->left = tail;
        tail->right = head;
        
        
        return head;
    }
};