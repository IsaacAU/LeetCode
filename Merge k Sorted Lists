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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeLists(begin(lists), end(lists));
    }
private:
    ListNode *mergeLists(vector<ListNode*>::iterator b, vector<ListNode*>::iterator e){
        if(b==e)    return nullptr;
        if(b==e-1)  return *b;
        if(b==e-2)  return mergeTwo(*b, *(b+1));
        auto m=b+(e-b)/2;
        return mergeTwo(mergeLists(b,m), mergeLists(m,e));
    }
    ListNode *mergeTwo(ListNode *first, ListNode *second){
        ListNode dummy(-1);
        ListNode *head=&dummy;
        while(first && second){
            if(first->val<second->val){
                head->next=first;
                head=head->next;
                first=first->next;
            }else{
                head->next=second;
                head=head->next;
                second=second->next;
            }
        }
        if(first)
            head->next=first;
        if(second)
            head->next=second;
        return dummy.next;
    }
};
