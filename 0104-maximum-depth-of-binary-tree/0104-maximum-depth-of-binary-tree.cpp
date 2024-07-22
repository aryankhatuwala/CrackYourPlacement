/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int func(TreeNode* root)
    {
        if(!root) return 0;

        int lefti=func(root->left);
        int righti=func(root->right);
        return 1+max(lefti,righti);
    }
    int maxDepth(TreeNode* root) {
        return func(root);
    }
};