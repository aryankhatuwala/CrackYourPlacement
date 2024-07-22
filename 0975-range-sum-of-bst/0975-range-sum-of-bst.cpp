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
    int func(TreeNode* root, int low, int high)
    {
        if(!root) return 0;

        int cur=root->val;
        int one,two,three;
        one=two=three=0;

        if(cur>=low and cur<=high){
        one=cur;
        }
        if(cur>=low) 
        two=func(root->left,low,high);
        if(cur<=high)
        three=func(root->right, low, high);
        return one+two+three;
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        return func(root,low,high);
        return sum;
    }
};