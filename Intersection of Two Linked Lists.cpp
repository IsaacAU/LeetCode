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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return nullptr;
        ListNode *end=headA;
        while(end->next)  end=end->next;
        if(!headB->next){
            if(headB==end)  return headB;
            else return nullptr;
        }
        end->next=headA;
        ListNode *fast=headB->next->next, *slow=headB->next;
        while(fast){
            if(fast==slow)  break;
            fast=fast->next;
            if(!fast)   break;
            fast=fast->next;
            slow=slow->next;
        }
        if(!fast){
            end->next=nullptr;
            return nullptr;
        }
        fast=headB;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        end->next=nullptr;
        return slow;
    }
};
