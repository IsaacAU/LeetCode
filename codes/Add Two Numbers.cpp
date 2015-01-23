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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int c=0;
        ListNode dummy(-1);
        ListNode *nd=&dummy;
        while(l1 || l2){
            int x=0, y=0;
            if(l1){
                x=l1->val;
                l1=l1->next;
            }
            if(l2){
                y=l2->val;
                l2=l2->next;
            }
            nd->next = new ListNode((x+y+c)%10);
            c=(x+y+c)/10;
            nd=nd->next;
        }
        if(c)
            nd->next = new ListNode(1);
        return dummy.next;
    }
};
