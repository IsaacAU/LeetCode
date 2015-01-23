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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildWithIter(begin(preorder), end(preorder), begin(inorder), end(inorder));
    }
private:
    TreeNode *buildWithIter(vector<int>::iterator preB, vector<int>::iterator preE, vector<int>::iterator inB, vector<int>::iterator inE){
        if(preB==preE)  return nullptr;
        TreeNode *root=new TreeNode(*preB);
        if(next(preB)==preE)    return root;
        auto inM=find(inB, inE, *preB);
        auto preM=next(preB, 1+distance(inB, inM));
        root->left=buildWithIter(next(preB), preM, inB, inM);
        root->right=buildWithIter(preM, preE, next(inM), inE);
        return root;
    }
};
