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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(-1); dummy.next=head;
        ListNode *prev=&dummy, *pivot=&dummy;
        while(head){
            if(head->val<x){
                if(pivot->next==head){
                    pivot=head;
                    prev=head;
                    head=head->next;
                }else{
                    prev->next=head->next;
                    ListNode *tmp=pivot->next;
                    pivot->next=head;
                    head->next=tmp;
                    pivot=head;
                    head=prev->next;
                }
            }else{
                prev=head;
                head=head->next;
            }
        }
        return dummy.next;
    }
};
