// Method 1
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
    bool isBalanced(TreeNode *root) {
        int depth=0;
        return search(root, depth);
    }
private:
    bool search(TreeNode *root, int &depth){
        if(!root)   return  true;
        ++depth;
        int left=depth, right=depth;
        if(!search(root->left, left))   return false;
        if(!search(root->right, right)) return false;
        depth=max(left, right);
        return abs(left-right)<=1;
    }
};

// Method 2
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
    bool isBalanced(TreeNode *root) {
        return balanceDepth(root)>=0;
    }
private:
    int balanceDepth(TreeNode *root){
        if(!root)   return 0;
        int left=balanceDepth(root->left);
        int right=balanceDepth(root->right);
        if(left<0 || right<0 || abs(left-right)>1)
            return -1;
        return max(left, right)+1;
    }
};
