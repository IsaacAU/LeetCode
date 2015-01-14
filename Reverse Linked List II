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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n || !head || !head->next)    return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *toPrev=&dummy, *toCur=head;
        n-=m;
        while(--m){
            toPrev=toCur;
            toCur=toCur->next;
        }
        ListNode *fromPrev=toCur, *fromCur=toCur->next;
        while(n--){
            fromPrev->next=fromCur->next;
            toPrev->next=fromCur;
            fromCur->next=toCur;
            toCur=fromCur;
            fromCur=fromPrev->next;
        }
        return dummy.next;
    }
};
