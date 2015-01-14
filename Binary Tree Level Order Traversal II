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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if(!root)   return res;
        res.push_back(vector<int>());
        queue<TreeNode*> q;
        q.push(root);
        int cur=1, next=0;
        while(!q.empty()){
            TreeNode *nd=q.front(); q.pop();
            if(nd->left){
                q.push(nd->left);
                ++next;
            }
            if(nd->right){
                q.push(nd->right);
                ++next;
            }
            res.back().push_back(nd->val);
            if(--cur==0 && next){
                swap(cur, next);
                res.push_back(vector<int>());
            }
        }
        reverse(begin(res), end(res));
        return move(res);
    }
};
