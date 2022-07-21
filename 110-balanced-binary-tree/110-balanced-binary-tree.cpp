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
    int check(TreeNode*root)
    {
        if(root==nullptr)
            return 0;
        
        int l1 = check(root->left);
        if(l1==-1)
            return -1;
        int l2 = check(root->right);
        
        if(l2==-1)
            return -1;
        if(abs(l1-l2)>1)
        {
            return -1;
        }
        
        return max(l1,l2)+1;
    }
    bool isBalanced(TreeNode* root) {
        
        bool ok = true;
        
        if(check(root)==-1)
            return  false;
        
        return true;
    }
};