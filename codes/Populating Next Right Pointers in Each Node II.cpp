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
        TreeLinkNode *nextHead=nullptr, *prev=nullptr;
        while(root){
            while(root){
                if(root->left){
                    if(prev){
                        prev->next=root->left;
                        prev=prev->next;
                    }else{
                        nextHead=root->left;
                        prev=root->left;
                    }
                }
                if(root->right){
                    if(prev){
                        prev->next=root->right;
                        prev=prev->next;
                    }else{
                        nextHead=root->right;
                        prev=root->right;
                    }
                }
                root=root->next;
            }
            root=nextHead;
            nextHead=nullptr;
            prev=nullptr;
        }
    }
};
