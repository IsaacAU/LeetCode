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
    bool isSymmetric(TreeNode *root) {
        return !root || symmetric(root->left, root->right);
    }
private:
    bool symmetric(TreeNode *nd1, TreeNode *nd2){
        if(!nd1 && !nd2)    return true;
        if(!nd1 || !nd2)    return false;
        return nd1->val==nd2->val && symmetric(nd1->left, nd2->right) && symmetric(nd1->right, nd2->left);
    }
};
