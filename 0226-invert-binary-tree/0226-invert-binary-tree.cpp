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
    TreeNode* func(TreeNode* root)
    {
        if(!root) return nullptr;
        
        auto lefti=func(root->left);
        auto righti=func(root->right);

        root->left=righti;
        root->right=lefti;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return func(root);
    } 
};