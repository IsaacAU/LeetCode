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
        if(!head || !head->next)    return head;
        int n=1;
        ListNode *end=head;
        while(end->next){
            ++n;
            end=end->next;
        }
        k%=n;
        if(k==0)    return head;
        n-=k;
        ListNode *nd=head;
        while(--n)  nd=nd->next;
        end->next=head;
        head=nd->next;
        nd->next=nullptr;
        return head;
    }
};
