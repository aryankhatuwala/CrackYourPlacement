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
    int func(TreeNode* root, int &ans)
    {
        if(!root) return 0;

        int lefti=func(root->left,ans);
        int righti=func(root->right,ans);
        
        ans=max(ans,lefti+righti);

        return 1+max(lefti,righti);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int temp=func(root,ans);
        return ans;
    }
};