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
    int dfs(TreeNode* root, map<TreeNode*,int>&mp)
    {
        if(root == nullptr)
        {
            return 0;
        }
        
        int l1 =dfs(root->left,mp);
        int r1 =dfs(root->right,mp);
        
       // cout<<l1<<" "<<r1<<" "<<root->val<<endl;
        int mx =max(mp[root],l1+r1+1);
        mp[root] = mx;
        return max(l1,r1)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        map<TreeNode*,int>mp;
        
        dfs(root,mp);
        
        int mx=0;
        
        for(auto i:mp)
        {
            mx=max(mx,i.second);
        }
        
        return mx-1;
    }
};