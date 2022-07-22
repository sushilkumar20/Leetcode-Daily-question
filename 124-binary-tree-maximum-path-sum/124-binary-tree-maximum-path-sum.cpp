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
    int solve(TreeNode*root, int &sum)
    {
        if(root==nullptr)
            return 0;
        
        if(root->left==nullptr&&root->right == nullptr)
        {
            sum=max(sum,root->val);
            
            if(root->val<0)
                return 0;
            
            return root->val;
        }
        
        int leftP = solve(root->left,sum);
        int rightP = solve(root->right,sum);
        
        sum = max(sum,leftP+rightP+root->val);
        
        int mx =max(leftP,rightP);
        
        if(mx+root->val<0)
            return 0;
        
        return mx+root->val;
    }
    int maxPathSum(TreeNode* root) {
        
        int sum = INT_MIN;
        
        solve(root,sum);
        
        return sum;
    }
};