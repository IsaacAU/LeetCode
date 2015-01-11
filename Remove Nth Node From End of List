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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *nd=head;
        while(--n) nd=nd->next;
        if(!nd->next){
            nd=head->next;
            delete head;
            return nd;
        }
        ListNode *pre=nullptr, *cur=head;
        while(nd->next){
            pre=cur;
            cur=cur->next;
            nd=nd->next;
        }
        pre->next=cur->next;
        delete cur;
        return head;
    }
};
