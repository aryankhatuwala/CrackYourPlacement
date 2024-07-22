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
        if(root==p or root==q) return root;

        auto lefti=func(root->left,p,q);
        auto righti=func(root->right,p,q);
        if(lefti and righti) return root;
        if(lefti) return lefti;
        return righti;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p,q);
    }
};