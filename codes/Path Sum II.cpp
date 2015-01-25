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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if(!root)   return res;
        vector<int> path;
        search(root, sum, res, path);
        return res;
    }
private:
    void search(TreeNode *root, int sum,  vector<vector<int>> &res, vector<int> &path){
        path.push_back(root->val);
        sum-=root->val;
        if(!root->left && !root->right){
            if(sum==0)
                res.push_back(path);
            path.pop_back();
            return;
        }
        if(root->left)  search(root->left, sum, res, path);
        if(root->right) search(root->right, sum, res, path);
        path.pop_back();
    }
};
