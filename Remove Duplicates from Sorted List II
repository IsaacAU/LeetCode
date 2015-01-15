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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *prev=&dummy;
        while(head){
            bool rep=false;
            while(head->next && head->val==head->next->val){
                rep=true;
                prev->next=head->next;
                delete head;
                head=head->next;
            }
            if(!rep && !head->next)
                break;
            if(rep){
                prev->next=head->next;
                delete head;
                head=prev->next;
            }else{
                prev=head;
                head=prev->next;
            }
        }
        return dummy.next;
    }
};
