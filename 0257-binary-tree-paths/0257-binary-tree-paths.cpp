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
    void func(TreeNode* root, string str, vector<string>&ans)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            str+= to_string(root->val);
            ans.push_back(str);
            return;
        }
        
        if(root->left)
        func(root->left, str+to_string(root->val)+"->",ans);

        if(root->right)
        func(root->right, str+to_string(root->val)+"->",ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        if(!root) return {};

        vector<string>ans;
        func(root,"",ans);
        return ans;
    }
};