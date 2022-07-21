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
    int check(TreeNode*root, bool &ok)
    {
        if(root==nullptr)
            return 0;
        
        int l1 = check(root->left,ok);
        int l2 = check(root->right,ok);
        
        if(abs(l1-l2)>1)
        {
            ok=false;
        }
        
        return max(l1,l2)+1;
    }
    bool isBalanced(TreeNode* root) {
        
        bool ok = true;
        
        check(root,ok);
        
        return ok;
    }
};