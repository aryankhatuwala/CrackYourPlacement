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
    TreeNode* func(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 and root2) return root2;
        if(!root2 and root1) return root1;
        if(!root1 and !root2) return nullptr;

        int sum=root1->val+root2->val;
        // TreeNode* temp=new TreeNode(sum);
        root1->val=sum;

        root1->left=func(root1->left, root2->left);
        root1->right=func(root1->right, root2->right);

        return root1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return func(root1, root2);
    }
};