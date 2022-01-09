/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //1.copy list
    void copyList(Node *head) {
        Node *c = head;
        while(c != NULL) {
            Node *f = c->next;
            Node *newNode = new Node(c->val);
            c->next=newNode;
            newNode->next=f;
            c=f;
        
        }
    }
    
    
    
    //2.copy random pointers
    void copyRandomPointers(Node *curr) {
        while(curr!=NULL) {
            Node *random = curr->random;
            if(random!=NULL) {
                curr->next->random=random->next;
            }
            curr=curr->next->next;
        }
    }
    
    //3.deattach new list with old list
    Node* extractList(Node *curr) {
        Node *newHead = new Node(-1);
        Node *prev = newHead;
        
        while(curr!=NULL) {
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev=prev->next;
            curr=curr->next;
        }
        return newHead->next;
    }
    
    Node* copyRandomList(Node* head) {
        copyList(head);
        copyRandomPointers(head);
        head = extractList(head);
        return head;
    }
};