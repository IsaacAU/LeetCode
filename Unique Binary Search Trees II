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
    vector<TreeNode *> generateTrees(int n) {
        vector<int> arr;    arr.reserve(n);
        for(int i=1; i<=n; ++i)
            arr.push_back(i);
        vector<TreeNode*> res=generate(begin(arr), end(arr));
        return move(res);
    }
private:
    vector<TreeNode*> generate(vector<int>::iterator b, vector<int>::iterator e){
        vector<TreeNode*> res;
        if(b==e){
            res.push_back(nullptr);
            return res;
        }
        for(auto i=b; i<e; ++i){
            vector<TreeNode*> left=generate(b,i);
            vector<TreeNode*> right=generate(i+1,e);
            for(auto x:left){
                for(auto y:right){
                    TreeNode *root=new TreeNode(*i);
                    root->left=x;
                    root->right=y;
                    res.push_back(root);
                }
            }
        }
    }
};
