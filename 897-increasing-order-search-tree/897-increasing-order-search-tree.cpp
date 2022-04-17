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
    TreeNode* inorder(TreeNode *root,TreeNode *next =nullptr)
    {
       if(root ==nullptr)
           return next;
        root->right = inorder(root->right,next);
        
        TreeNode*temp =inorder(root->left,root);
        
        root->left =nullptr;
        return temp;
    }
    TreeNode* increasingBST(TreeNode* root) {
        
     return inorder(root, nullptr);
    
    }
};