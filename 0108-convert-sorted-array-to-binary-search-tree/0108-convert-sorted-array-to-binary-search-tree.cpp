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
    TreeNode* func(int left, int right,vector<int>& nums )
    {
        if(left>right) return nullptr;

        int mid=left+(right-left)/2;
        TreeNode* cur=new TreeNode(nums[mid]);
        cur->left=func(left,mid-1,nums);
        cur->right=func(mid+1,right,nums);

        return cur;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(0,nums.size()-1,nums);
    }
};