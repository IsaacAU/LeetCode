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
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next)    return head;
        int n=0;
        ListNode *nd=head;
        while(nd){
            ++n;
            nd=nd->next;
        }
        n/=2;
        nd=head;
        while(--n)  nd=nd->next;
        ListNode *second=nd->next;  nd->next=nullptr;
        return merge(sortList(head), sortList(second));
    }
private:
    ListNode *merge(ListNode *first, ListNode *second){
        ListNode dummy(-1), *prev=&dummy;
        while(first && second){
            if(first->val<second->val){
                prev->next=first;
                first=first->next;
            }else{
                prev->next=second;
                second=second->next;
            }
            prev=prev->next;
        }
        if(first)   prev->next=first;
        if(second)  prev->next=second;
        return dummy.next;
    }
};
