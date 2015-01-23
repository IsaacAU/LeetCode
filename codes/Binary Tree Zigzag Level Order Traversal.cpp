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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(!root)   return res;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool left=true;
        int cur=1, next=0;
        res.push_back(vector<int>());
        res.back().reserve(cur);
        TreeNode *nd=nullptr;
        while(!dq.empty()){
            if(left){
                nd=dq.front();
                dq.pop_front();
            }else{
                nd=dq.back();
                dq.pop_back();
            }
            res.back().push_back(nd->val);
            if(nd->left)    ++next;
            if(nd->right)   ++next;
            if(left){
                if(nd->left)    dq.push_back(nd->left);
                if(nd->right)   dq.push_back(nd->right);
            }else{
                if(nd->right)   dq.push_front(nd->right);
                if(nd->left)    dq.push_front(nd->left);
            }
            if(--cur==0 && next){
                swap(cur, next);
                left=!left;
                res.push_back(vector<int>());
                res.back().reserve(cur);
            }
        }
        return move(res);
    }
};
