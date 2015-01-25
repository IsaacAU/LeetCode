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
        ListNode dummy(-1); dummy.next=head;
        ListNode *prev=&dummy, *nd=head;
        while(--n)
            nd=nd->next;
        while(nd->next){
            prev=prev->next;
            nd=nd->next;
        }
        ListNode *tmp=prev->next;
        prev->next=tmp->next;
        delete tmp;
        return dummy.next;
    }
};
