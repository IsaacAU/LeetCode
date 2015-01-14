/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)   return;
        queue<TreeLinkNode*> q;
        q.push(root);
        int cur=1, next=0;
        while(!q.empty()){
            TreeLinkNode *nd=q.front();
            q.pop();
            if(nd->left){
                q.push(nd->left);
                ++next;
            }
            if(nd->right){
                q.push(nd->right);
                ++next;
            }
            if(--cur==0){
                cur=next;
                next=0;
            }else if(!q.empty()){
                nd->next=q.front();
            }
        }
    }
};
