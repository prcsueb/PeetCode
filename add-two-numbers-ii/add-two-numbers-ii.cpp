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
    ListNode* reverse(ListNode *head) {
        if(head == NULL) {
            return head;
        }
        
        ListNode *prev = NULL;
        ListNode *current = head;
        ListNode *nextPointer = head->next;
        while(nextPointer != NULL) {
            current->next = prev;
            prev = current;
            current = nextPointer;
            nextPointer = nextPointer -> next;
        }
        
        current->next = prev;
        
        return current;
    }
    
    ListNode *addTwoNumber(ListNode *p, ListNode *q) {
        ListNode *ans = NULL;
        ListNode *ansHead = new ListNode(0);
        ListNode *l1 = p, *l2 =  q;
        ans = ansHead;
        int carry = 0;
        bool check = true;
        while(l1 != NULL || l2!=NULL) {
            int a = 0, b = 0;
            
            if(l1 != NULL) {
                a = l1->val;
            }
            
            if(l2 != NULL) {
                b = l2->val;
            }
            
            int sum = a + b + carry;
            carry = 0;
            if(sum > 9) {
                carry = 1;
            }
    
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
            if(l1 != NULL) {
                l1 = l1->next;
            }
            if(l2 != NULL) {
                l2 = l2->next;
            }
        }
        if(carry != 0) {
            ListNode *node = new ListNode(carry);
            ans->next = node;
        }
        return ansHead->next;
    }
    
    void print(ListNode* l) {
        while(l != NULL) {
            cout << l->val << " , ";
            l = l -> next;
        }
        cout << "\n";
        return;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);    
        l2 = reverse(l2);  
        print(l1);
        print(l2);
        
        return reverse(addTwoNumber(l1, l2));       
    }
};