/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root || !root->left && !root->right)    return;
        if(!root->left){
            flatten(root->right);
            return;
        }
        TreeNode *left=root->left, *right=root->right;
        root->left=nullptr;
        flatten(left);
        root->right=left;
        while(left->right)
            left=left->right;
        left->right=right;
        flatten(right);
    }
};
