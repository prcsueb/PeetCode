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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* curr=head;
        while(curr!=NULL) {
            ListNode* prev=curr->next;
            if(prev==NULL)break;
            if(prev->val==curr->val) {
                curr->next=prev->next;
                prev->next=NULL;
            }
            else {
                curr=curr->next;
            }
        }
        return head;
    }
};