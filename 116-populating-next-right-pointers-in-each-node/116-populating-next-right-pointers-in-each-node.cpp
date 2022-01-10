/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *black = root;
        //khud null na hoi and last level bhi na hovo joye
        while(black != NULL && black->left!=NULL) {
            Node *node = black;
            while(true) {
                node->left->next = node->right;
                if(node->next==NULL) {
                    break;
                }
                node->right->next=node->next->left;
                node=node->next;
            }
            black=black->left;
        }
        
        return root;
    }
};