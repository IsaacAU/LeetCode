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
        if(!head || !head->next)    return head;
        ListNode *pre1=nullptr, *cur1=head;
        while(cur1 && cur1->val<x){
            pre1=cur1;
            cur1=cur1->next;
        }
        if(!cur1)   return head;
        ListNode *pre2=cur1, *cur2=cur1->next;
        while(cur2){
            if(cur2->val<x){
                pre2->next=cur2->next;
                cur2->next=cur1;
                if(pre1){
                    pre1->next=cur2;
                    pre1=pre1->next;
                }else{
                    head=cur2;
                    pre1=head;
                }
                cur2=pre2->next;
            }else{
                pre2=cur2;
                cur2=cur2->next;
            }
        }
        return head;
    }
};
