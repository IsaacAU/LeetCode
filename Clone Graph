/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)   return nullptr;
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        UndirectedGraphNode *copy=nullptr;
        while(!q.empty()){
            UndirectedGraphNode *nd=q.front();
            q.pop();
            UndirectedGraphNode *newNode=new UndirectedGraphNode(nd->label);
            if(!copy)   copy=newNode;
            m[nd]=newNode;
            for(auto it=begin(nd->neighbors); it!=end(nd->neighbors); ++it){
                if(m.count(*it)==0) q.push(*it);
            }
        }
        for(auto it=begin(m); it!=end(m); ++it){
            UndirectedGraphNode *orgNode=it->first, *newNode=it->second;
            for(auto jt=begin(orgNode->neighbors); jt!=end(orgNode->neighbors); ++jt){
                newNode->neighbors.push_back(m[*jt]);
            }
        }
        return copy;
    }
};
