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
    // use stack
    vector<int> inorderTraversal(TreeNode *root) {
        if(!root)   return vector<int>();
        stack<TreeNode*> stk;
        TreeNode *nd=root;
        vector<int> res;
        while(nd || !stk.empty()){
            if(nd){
                stk.push(nd);
                nd=nd->left;
            }else{
                nd=stk.top();
                stk.pop();
                res.push_back(nd->val);
                nd=nd->right;
            }
        }
        return res;
    }
    // morris traversal
        vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)   return res;
        while(root){
            if(root->left){
                TreeNode *nd=root->left;
                while(nd->right && nd->right!=root) nd=nd->right;
                if(!nd->right){
                    nd->right=root;
                    root=root->left;
                }else{
                    nd->right=nullptr;
                    res.push_back(root->val);
                    root=root->right;
                }
            }else{
                res.push_back(root->val);
                root=root->right;
            }
        }
        return res;
    }
};
