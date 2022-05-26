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
    class Node {
        public:
        int val;
        Node *prev = NULL;
        Node *next = NULL;
        Node(int v) {
            val = v;
        }
    };
    
    Node *head = new Node(-1);
    Node *tail = new Node(-1);
    
    int noOfNodes() {
        if(head->next->val == -1) return 0;
        else if(head->next == tail->prev) return 1;
        else if(head->next != tail->prev) return 2;
        return 0;
    }
    
    void insertNext(Node *node, Node *newNode) {
        node->next->prev = newNode;
        newNode->next = node->next;
        newNode->prev = node;
        node->next = newNode;
    }
    
    void insertPrev(Node *node, Node *newNode) {
        node->prev->next=newNode;
        newNode->prev=node->prev;
        newNode->next=node;
        node->prev = newNode;
    }
    
    void helper(TreeNode *root) {
        if(!root) return;
        int count = noOfNodes();
        Node *newNode = new Node(root->val);
        if(count == 0) {
            insertNext(head, newNode);
        } else if(count == 1 && head->next->val != root->val) {
            if(root->val < head->next->val) {
                insertNext(head,newNode);
            } else if(root->val > head->next->val) {
                insertPrev(tail,newNode);
            }
        } else if(count == 2 && head->next->val != root->val && tail->prev->val != root->val) {
            if(root->val < head->next->val) {
                head->next->next->val = head->next->val;
                head->next->val=root->val;
            } else if(root->val < tail->prev->val) {
                tail->prev->val = root->val;
            }
        }
        helper(root->left);
        helper(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if(!root->left && !root->right) return -1;
        

        head->next = tail;
        tail->prev = head;
        
        helper(root);
        int count = noOfNodes();
        if(count == 0 || count == 1) {
            return -1;
        }
        return tail->prev->val;
    }
};