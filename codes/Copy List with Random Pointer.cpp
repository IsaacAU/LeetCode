/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    // method 1
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)   return nullptr;
        RandomListNode *nd=head, *copy=new RandomListNode(head->label);
        map<RandomListNode*,RandomListNode*> m;
        m[head]=copy;
        RandomListNode *cur=copy;
        while(nd->next){
            cur->next=new RandomListNode(nd->next->label);
            nd=nd->next;
            cur=cur->next;
            m[nd]=cur;
        }
        for(auto it=begin(m); it!=end(m); ++it){
            if(it->first->random)
                it->second->random = m[it->first->random];
        }
        return copy;
    }
    // method 2
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *nd=head;
        while(nd){
            RandomListNode *tmp=nd->next;
            nd->next=new RandomListNode(nd->label);
            nd->next->next=tmp;
            nd=tmp;
        }
        nd=head;
        while(nd){
            if(nd->random)
                nd->next->random=nd->random->next;
            nd=nd->next->next;
        }
        RandomListNode dummy(-1);
        RandomListNode *prev=&dummy;
        nd=head;
        while(nd){
            prev->next=nd->next;
            nd->next=nd->next->next;
            prev=prev->next;
            nd=nd->next;
        }
        return dummy.next;
    }
};
