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
    bool check(TreeNode *root, long long mn, long long mx)
    {
        if(root==nullptr)
            return true;
        
        if(root->val>=mx||root->val<=mn)
            return false;
        
        bool kk = check(root->left,mn,root->val);
        bool kk1 = check(root->right,root->val,mx);
        
        return kk&&kk1;
        
    }
    bool isValidBST(TreeNode* root) {
        
        return check(root,-1e10,1e10);
    }
};