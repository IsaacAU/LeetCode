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
    int maxPathSum(TreeNode *root) {
        if(!root)   return 0;
        int res=INT_MIN;
        maxWR(root, res);
        return res;
    }
private:
    int maxWR(TreeNode *root, int &res){
        int r=root->val;
        int left=INT_MIN, right=INT_MIN;
        if(root->left){
            left=maxWR(root->left, res);
        }
        if(root->right){
            right=maxWR(root->right, res);
        }
        r+=max(0, max(left, right));
        res=max(res,r);
        if(left>0 && right>0)   res=max(res, left+right+root->val);
        return r;
    }
};
