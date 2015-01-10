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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *pre=&dummy, *nd=head;
        while(nd && nd->next){
            ListNode *next=nd->next, *nextnext=next->next;
            pre->next=next;
            next->next=nd;
            nd->next=nextnext;
            pre=nd;  nd=nextnext;
        }
        return dummy.next;
    }
};
