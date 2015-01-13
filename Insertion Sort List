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
    ListNode *insertionSortList(ListNode *head) {
        if(!head || !head->next)    return head;
        ListNode *nd=head;
        while(nd->next){
            if(nd->val>nd->next->val){
                ListNode *cur=nd->next;
                nd->next=cur->next;
                if(head->val>=cur->val){
                    cur->next=head;
                    head=cur;
                }else{
                    ListNode *nd1=head;
                    while(nd1->next->val<cur->val)
                        nd1=nd1->next;
                    cur->next=nd1->next;
                    nd1->next=cur;
                }
            }else
                nd=nd->next;
        }
        return head;
    }
};
