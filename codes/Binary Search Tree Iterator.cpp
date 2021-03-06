/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        nd=root;
        while(nd && nd->left){
            stk.push(nd);
            nd=nd->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return nd;
    }

    /** @return the next smallest number */
    int next() {
        int val=nd->val;
        if(nd->right){
            nd=nd->right;
            while(nd->left){
                stk.push(nd);
                nd=nd->left;
            }
        }else if(!stk.empty()){
            nd=stk.top();
            stk.pop();
        }else
            nd=nullptr;
        return val;
    }
private:
    stack<TreeNode*> stk;
    TreeNode *nd;
};
 
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
