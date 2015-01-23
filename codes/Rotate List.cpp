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
    ListNode *rotateRight(ListNode *head, int k) {
        if(k==0 || !head || !head->next)   return head;
        ListNode *nd=head;
        int len=1;
        while(nd->next){
            ++len;
            nd=nd->next;
        }
        k=k%len;
        if(k==0)    return head;
        k=len-k;
        ListNode *pre=nullptr, *end=nd;
        nd=head;
        while(k--){
            pre=nd;
            nd=nd->next;
        }
        pre->next=nullptr;  end->next=head;
        head=nd;
        return head;
    }
};
