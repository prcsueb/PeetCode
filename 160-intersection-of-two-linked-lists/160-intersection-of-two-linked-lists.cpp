/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *slow=headA;
        ListNode *fast=headB;
        int len1 = 0;
        int len2 = 0;
        while(slow!=NULL) {
            slow = slow->next;len1++;
        }
        while(fast!=NULL) {
            fast = fast->next;len2++;
        }
        int diff = abs(len1-len2);
        slow=headA;
        fast=headB;
        if(len1>len2) {
            while(diff--) {
                slow=slow->next;
            }
            while(slow!=fast && slow!=NULL && fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        } else if(len2>len1) {
            while(diff--) {
                fast=fast->next;
            }
            while(slow!=fast && slow!=NULL && fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        } else {
            while(slow!=fast && slow!=NULL && fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        
        return fast==slow? slow:NULL;
    }
};