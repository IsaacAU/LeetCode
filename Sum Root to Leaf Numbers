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
    int sumNumbers(TreeNode *root) {
        if(!root)   return 0;
        int sum=0;
        traverse(root, sum);
        return sum;
    }
private:
    void traverse(TreeNode *nd, int &sum){
        if(!nd->left && !nd->right) sum+=nd->val;
        else{
            if(nd->left){
                nd->left->val+=10*nd->val;
                traverse(nd->left, sum);
            }
            if(nd->right){
                nd->right->val+=10*nd->val;
                traverse(nd->right, sum);
            }
        }
    }
};
