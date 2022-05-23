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
    int getLen(ListNode *x) {
        int len = 0;
        while(x != NULL) {
            x=x->next;
            ++len;
        }
        return len;
    }
    ListNode *moveByDist(ListNode *x, int dist) {
        while(dist--) {
            x=x->next;
        }
        return x;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aLen = getLen(headA);
        int bLen = getLen(headB);
        if(aLen > bLen) {
            headA = moveByDist(headA, aLen-bLen);
        } else if(bLen > aLen) {
            headB = moveByDist(headB, bLen-aLen);
        }
        
        while(headA!=NULL && headB!=NULL) {
            if(headA==headB) {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};