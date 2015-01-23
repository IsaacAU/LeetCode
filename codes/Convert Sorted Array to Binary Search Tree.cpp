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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return WithIter(begin(num), end(num));
    }
private:
    TreeNode *WithIter(vector<int>::iterator b, vector<int>::iterator e){
        if(b==e)    return nullptr;
        auto m=next(b, distance(b,e)/2);
        TreeNode *root=new TreeNode(*m);
        root->left=WithIter(b, m);
        root->right=WithIter(next(m), e);
        return root;
    }
};
