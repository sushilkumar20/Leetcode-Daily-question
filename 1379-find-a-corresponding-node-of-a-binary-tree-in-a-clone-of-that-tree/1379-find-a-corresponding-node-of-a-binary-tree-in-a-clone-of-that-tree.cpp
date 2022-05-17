/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode * dfs(TreeNode *root, TreeNode*target)
    {
        if(root==nullptr)
            return nullptr;
        
        if(root->val==target->val)
            return root;
        TreeNode *left = dfs(root->left,target);
        if(left!=nullptr)
            return left;
        TreeNode*right = dfs(root->right,target);
        
        return right;
        
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        
        return dfs(cloned, target);
        
    }
};