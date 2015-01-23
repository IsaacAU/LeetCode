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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildIter(begin(inorder), end(inorder), begin(postorder), end(postorder));
    }
private:
    TreeNode *buildIter(vector<int>::iterator inB, vector<int>::iterator inE, vector<int>::iterator postB, vector<int>::iterator postE){
        if(inB==inE)    return nullptr;
        if(next(inB)==inE)  return new TreeNode(*inB);
        TreeNode *root=new TreeNode(*prev(postE));
        vector<int>::iterator pos=find(inB, inE, root->val);
        root->left=buildIter(inB, pos, postB, postB+(pos-inB));
        root->right=buildIter(pos+1, inE, postB+(pos-inB), prev(postE));
        return root;
    }
};
