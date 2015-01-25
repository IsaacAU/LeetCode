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
        ListNode *prev=&dummy;
        while(prev->next && prev->next->next){
            ListNode *tmp=prev->next;
            prev->next=tmp->next;
            prev=prev->next;
            tmp->next=prev->next;
            prev->next=tmp;
            prev=prev->next;
        }
        return dummy.next;
    }
};
