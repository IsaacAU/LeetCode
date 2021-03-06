/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// morris traverse
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if(!root)   return;
        TreeNode *wrong1=nullptr, *wrong2=nullptr;
        morris(root, wrong1, wrong2);
        swap(wrong1->val, wrong2->val);
    }
private:
    void morris(TreeNode *root, TreeNode *&wrong1, TreeNode *&wrong2){
        TreeNode *prev=nullptr;
        while(root){
            if(root->left){
                TreeNode *nd=root->left;
                while(nd->right && nd->right!=root)
                    nd=nd->right;
                if(!nd->right){
                    nd->right=root;
                    root=root->left;
                }else{
                    if(prev && root && prev->val>=root->val){
                        if(!wrong1) wrong1=prev;
                        wrong2=root;
                    }
                    nd->right=nullptr;
                    prev=root;
                    root=root->right;
                }
            }else{
                if(prev && root && prev->val>=root->val){
                    if(!wrong1) wrong1=prev;
                    wrong2=root;
                }
                prev=root;
                root=root->right;
            }
        }
    }
};

// recursion inorder traverse
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if(!root)   return;
        TreeNode *first=nullptr, *second=nullptr;
        traverse(root, nullptr, nullptr, first, second);
        swap(first->val, second->val);
    }
private:
    void traverse(TreeNode *root, TreeNode *leftBound, TreeNode *rightBound, TreeNode *&first, TreeNode *&second){
        if(root->left)  traverse(root->left, leftBound, root, first, second);
        if(leftBound && leftBound->val>root->val){
            if(!first)
                first=leftBound;
            second=root;
        }
        if(rightBound && rightBound->val<root->val){
            if(!first){
                first=root;
            }
            second=rightBound;
        }
        if(root->right) traverse(root->right, root, rightBound, first, second);
    }
};
