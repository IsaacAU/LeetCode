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
    // method 1
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
    // method 2
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1); dummy.next=head;
        ListNode *prev=&dummy;
        while(--m){
            prev=prev->next;
            --n;
        }
        ListNode *nd1=nullptr, *nd2=prev->next, *end=prev->next;
        while(n--){
            ListNode *tmp=nd2->next;
            nd2->next=nd1;
            nd1=nd2;
            nd2=tmp;
        }
        prev->next=nd1;
        end->next=nd2;
        return dummy.next;
    }
};
