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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k==1 || !head || !head->next)    return head;
        ListNode dummy(-1); dummy.next=head;
        ListNode *prev=&dummy, *cur=head;
        while(cur){
            int i=k;
            while(--i && cur)
                cur=cur->next;
            if(!cur)    break;
            while(prev->next!=cur){
                ListNode *nd=prev->next;
                prev->next=nd->next;
                nd->next=cur->next;
                cur->next=nd;
            }
            i=k;
            while(i--){
                prev=cur;
                cur=cur->next;
            }
        }
        return dummy.next;
    }
    // method 2
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k<=1 || !head || !head->next)    return head;
        ListNode dummy(-1);  dummy.next=head;
        ListNode *prev=&dummy;
        while(head){
            int i=k;
            while(head && i--)
                head=head->next;
            if(i>0)   break;
            ListNode *nd1=head, *nd2=prev->next, *end=prev->next;
            while(nd2!=head){
                ListNode *tmp=nd2->next;
                nd2->next=nd1;
                nd1=nd2;
                nd2=tmp;
            }
            prev->next=nd1;
            prev=end;   prev->next=head;
        }
        return dummy.next;
    }
};
