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
    bool isSubTree(TreeNode* root, TreeNode* subRoot)
    {
        // if(!subRoot) return root==nullptr;

        // if(!root) return subRoot==nullptr;

        if(!root or !subRoot) return root==nullptr and subRoot==nullptr;
        
        if(root->val == subRoot->val)
        {
            bool one=isSubTree(root->left, subRoot->left);
            bool two=isSubTree(root->right, subRoot->right);
            return one && two;
        }
        return false;

    }
    bool func(TreeNode* root, TreeNode* subRoot)
    {
        if(!root) return false;
        
        bool ans=isSubTree(root, subRoot);
        if(ans) return true;

        bool lefti=func(root->left, subRoot);
        bool righti=func(root->right, subRoot);
        return lefti || righti;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return func(root,subRoot);
    }
};