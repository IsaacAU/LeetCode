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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(!root)   return res;
        queue<TreeNode*> q;
        q.push(root);
        int cur=1, next=0;
        vector<int> v;
        while(!q.empty()){
            TreeNode *nd=q.front(); q.pop();  v.push_back(nd->val);
            if(nd->left)    {   q.push(nd->left);   ++next; }
            if(nd->right)   {   q.push(nd->right);  ++next; }
            if(--cur==0){
                cur=next;
                next=0;
                res.push_back(v);
                v.clear();
            }
        }
        return res;
    }
};
