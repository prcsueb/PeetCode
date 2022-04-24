/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mid(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * a = NULL;
        ListNode * b = head;
        ListNode * c = head->next;
        
        while(c != NULL) {
            b->next = a;
            a=b;
            b=c;
            c=c->next;
        }
        
        b->next=a;
        
        return b;
    }
    
    bool isPalindrome(ListNode* root) {
        if(root==NULL)return true;
        ListNode *middle = mid(root);
        ListNode *nh1 = root;
        ListNode *nh2 = reverse(middle);
        while(nh1!=middle && nh2!=NULL) {
            if(nh1->val != nh2->val) {
                return false;
            }
            nh1=nh1->next;
            nh2=nh2->next;
        }
        return true;
    }
};