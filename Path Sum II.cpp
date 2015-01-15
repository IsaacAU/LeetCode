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
        int cur;
        search(root, sum, res, path, cur);
        return res;
    }
private:
    void search(TreeNode *root, int sum, vector<vector<int>> &res, vector<int> &path, int cur){
        if(!root->left && !root->right){
            if(sum==cur+root->val){
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        if(root->left){
            path.push_back(root->val);  cur+=root->val;
            search(root->left, sum, res, path, cur);
            path.pop_back();  cur-=root->val;
        }
        if(root->right){
            path.push_back(root->val);  cur+=root->val;
            search(root->right, sum, res, path, cur);
            path.pop_back();   cur-=root->val;
        }
    }
};
