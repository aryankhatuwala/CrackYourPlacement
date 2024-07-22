/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* func(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return nullptr;
        if(p->val <=root->val and q->val>=root->val) return root;
        if(p->val >=root->val and q->val<=root->val) return root;

        auto lefti=func(root->left,p,q);
        if(lefti) return lefti;
        auto righti=func(root->right,p,q);
        return righti;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p,q);
    }
};