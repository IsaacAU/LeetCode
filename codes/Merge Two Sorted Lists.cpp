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
    // recursive
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *head;
        if(l1->val<l2->val){
            head=l1;
            head->next=mergeTwoLists(l1->next, l2);
        }else{
            head=l2;
            head->next=mergeTwoLists(l1, l2->next);
        }
        return head;
    }
    // iterative
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *prev=&dummy;
        while(l1 && l2){
            if(l1->val<l2->val){
                prev->next=l1;
                l1=l1->next;
            }else{
                prev->next=l2;
                l2=l2->next;
            }
            prev=prev->next;
        }
        if(l1)  prev->next=l1;
        if(l2)  prev->next=l2;
        return dummy.next;
    }
};
