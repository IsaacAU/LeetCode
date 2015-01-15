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
    // two stacks
    vector<int> postorderTraversal1(TreeNode *root) {
        if(!root)   return vector<int>();
        stack<TreeNode*> s1;
        stack<int> s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode *nd=s1.top();       s1.pop();
            s2.push(nd->val);
            if(nd->left)    s1.push(nd->left);
            if(nd->right)   s1.push(nd->right);
        }
        vector<int> res;
        res.reserve(s2.size());
        while(!s2.empty()){
            res.push_back(s2.top());
            s2.pop();
        }
        return move(res);
    }
    // one stack
    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> res;
        if(!root)   return res;
        TreeNode *prev=nullptr, *cur=nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            cur=stk.top();
            if(!prev || prev->left==cur || prev->right==cur){
                if(cur->left)
                    stk.push(cur->left);
                else if(cur->right)
                    stk.push(cur->right);
                else{
                    res.push_back(cur->val);
                    stk.pop();
                }
            }else if(cur->left==prev && cur->right){
                stk.push(cur->right);
            }else{
                res.push_back(cur->val);
                stk.pop();
            }
            prev=cur;
        }
        return res;
    }
    // morris traverse
    vector<int> postorderTraversal3(TreeNode *root) {
        vector<int> res;
        if(!root)   return res;
        TreeNode dummy(-1);
        dummy.left=root;
        TreeNode *prev=nullptr, *cur=&dummy;
        stack<int> stk;
        while(cur){
            if(cur->left){
                TreeNode *prev=cur->left;
                while(prev->right && prev->right!=cur)
                    prev=prev->right;
                if(!prev->right){
                    prev->right=cur;
                    cur=cur->left;
                }else{
                    prev->right=nullptr;
                    for(prev=cur->left; prev; prev=prev->right)
                        stk.push(prev->val);
                    while(!stk.empty()){
                        res.push_back(stk.top());
                        stk.pop();
                    }
                    cur=cur->right;
                }
            }else{
                cur=cur->right;
            }
        }
    }
};
