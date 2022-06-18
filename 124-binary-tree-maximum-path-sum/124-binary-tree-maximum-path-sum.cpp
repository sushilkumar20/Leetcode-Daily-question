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
    int dfs(TreeNode*root,int &mx,unordered_map<TreeNode*, int> &mp)
    {
        if(root==nullptr)
            return 0;
        
        int left=0;
        int right=0;
        
        if(mp.find(root->left)!=mp.end())
        {
            left = max(mp[root->left],0);
        }
        else
        {
            left = max( dfs(root->left,mx,mp),0);
        }
        
        if(mp.find(root->right)!=mp.end())
        {
            right = max(mp[root->right],0);
        }
        else
        {
            right = max( dfs(root->right,mx,mp),0);
        }
        
        mp[root] = left+right+root->val;
        
        mx=max(mx,mp[root]);
        
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        
        int mx=INT_MIN;
        unordered_map<TreeNode*, int> mp;
        
        dfs(root,mx,mp);
        
        return mx;
    }
};