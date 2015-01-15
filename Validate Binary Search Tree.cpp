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
    bool isValidBST(TreeNode *root) {
        if(!root)   return true;
        return valid(root, nullptr, nullptr);
    }
private:
    bool valid(TreeNode *nd, TreeNode *lower, TreeNode *upper){
        if(lower && nd->val<=lower->val || upper && nd->val>=upper->val)    return false;
        return (!nd->left || valid(nd->left, lower, nd)) && (!nd->right || valid(nd->right, nd, upper));
    }
};
