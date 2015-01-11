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
};
