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
};
