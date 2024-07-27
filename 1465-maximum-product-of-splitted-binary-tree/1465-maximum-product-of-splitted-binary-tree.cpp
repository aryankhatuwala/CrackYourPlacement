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
    long long findTotalSum(TreeNode* root)
    {
        if(!root) return 0;
        return root->val+ findTotalSum(root->left)+ findTotalSum(root->right);
    }
    long long func(TreeNode* root, long long &total, long long &ans, long long &mod)
    {
        if(!root) return 0;

        long long lefti=func(root->left,total,ans, mod);
        long long righti=func(root->right, total,ans, mod);

        ans=max(ans, ((total-lefti)*lefti));
        ans=max(ans, ((total-righti)*righti));

        return lefti+righti+root->val;
    }
    int maxProduct(TreeNode* root) {
        
        long long total=findTotalSum(root);
        long long ans=INT_MIN, mod=1e9+7;
        func(root,total,ans,mod);
        return int(ans%mod);

    }
};