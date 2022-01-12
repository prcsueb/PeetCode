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
    ListNode* middle(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != NULL && fast -> next ->next !=NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) {
            return l2;
        }
        if(l2==NULL) {
            return l1;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *pointer = dummy;
        while(l1!=NULL && l2!=NULL) {
            if(l1->val > l2->val) {
                pointer->next=l2;
                l2=l2->next;
            } else {
                pointer->next=l1;
                l1=l1->next;
            }
            pointer=pointer->next;
        }
        if(l1!=NULL) {
            pointer->next=l1;
        }
        if(l2!=NULL) {
            pointer->next=l2;
        }
        
        return dummy->next;
    }
    
    ListNode* merge(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* mid = middle(head);
        ListNode* nextNode = mid->next;
        mid->next=NULL;
        ListNode* l1 = merge(head);
        ListNode* l2 = merge(nextNode);
        return mergeLists(l1,l2);
    }
    ListNode* sortList(ListNode* head) {
        return merge(head);
    }
};





