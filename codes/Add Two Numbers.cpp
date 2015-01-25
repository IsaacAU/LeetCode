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
        int c=0;
        ListNode dummy(-1);
        ListNode *prev=&dummy;
        while(l1 || l2 || c){
            int x=0, y=0;
            if(l1){
                x=l1->val;
                l1=l1->next;
            }
            if(l2){
                y=l2->val;
                l2=l2->next;
            }
            prev->next=new ListNode((x+y+c)%10);
            prev=prev->next;
            c=(x+y+c)/10;
        }
        return dummy.next;
    }
};
