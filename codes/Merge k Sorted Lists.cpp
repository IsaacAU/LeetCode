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
        return merge(begin(lists), end(lists));
    }
private:
    ListNode *merge(vector<ListNode*>::iterator b, vector<ListNode*>::iterator e){
        if(b==e)    return nullptr;
        if(next(b)==e)  return *b;
        auto m=b+(e-b)/2;
        return mergeList(merge(b, m), merge(m,e));
    }
    ListNode *mergeList(ListNode *first, ListNode *second){
        ListNode dummy(-1);
        ListNode *prev=&dummy;
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
