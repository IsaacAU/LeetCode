/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head)   return nullptr;
        int n=0;
        ListNode *nd=head;
        while(nd){  ++n; nd=nd->next; }
        if(n==1)    return new TreeNode(head->val);
        n=n/2;
        nd=head;    ListNode *pre=nullptr;
        while(n--){ pre=nd; nd=nd->next; }
        pre->next=nullptr;
        TreeNode* root=new TreeNode(nd->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(nd->next);
        return root;
    }
};
