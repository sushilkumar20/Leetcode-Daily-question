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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==nullptr)
            return false;
        
        if(targetSum-root->val==0&&root->left==nullptr&&root->right==nullptr)
            return 1;
        
        
        
        targetSum-=root->val;
        
        bool left = hasPathSum(root->left,targetSum);
        bool right = hasPathSum(root->right,targetSum);
        targetSum+=root->val;
        
        if(left||right)
            return 1;
        
        return 0;
    }
};