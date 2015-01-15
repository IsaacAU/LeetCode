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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)   return res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *nd=stk.top(); stk.pop();
            res.push_back(nd->val);
            if(nd->right)   stk.push(nd->right);
            if(nd->left)    stk.push(nd->left);
        }
        return res;
    }
};
