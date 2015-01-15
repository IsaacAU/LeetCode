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
        TreeLinkNode *cur=root, *next=nullptr;
        while(cur){
            while(cur){
                if(cur->left){
                    next=cur->left;
                    break;
                }else if(cur->right){
                    next=cur->right;
                    break;
                }
                cur=cur->next;
            }
            if(!next)   break;
            TreeLinkNode *nd=next;
            while(cur){
                if(cur->left && nd!=cur->left){
                    nd->next=cur->left;
                    nd=nd->next;
                }
                if(cur->right && nd!=cur->right){
                    nd->next=cur->right;
                    nd=nd->next;
                }
                cur=cur->next;
            }
            cur=next;
            next=nullptr;
        }
    }
};
