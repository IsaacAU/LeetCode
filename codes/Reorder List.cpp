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
    void reorderList(ListNode *head) {
        if(!head)   return;
        int n=0;
        ListNode *nd=head;
        while(nd){
            ++n;
            nd=nd->next;
        }
        n/=2; nd=head;
        while(n--)  nd=nd->next;
        ListNode *right=nd->next;  nd->next=nullptr;
        ListNode *pre=nullptr;
        while(right){
            ListNode *tmp=right->next;
            right->next=pre;
            pre=right;
            right=tmp;
        }
        nd=head;   right=pre;
        while(nd && right){
            ListNode *tmp1=nd->next, *tmp2=right->next;
            nd->next=right;
            right->next=tmp1;
            nd=tmp1;
            right=tmp2;
        }
    }
};
