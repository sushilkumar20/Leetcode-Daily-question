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
    bool pos(unordered_map<int,int> mp)
    {
        int x=0;
        for(auto i:mp)
        {
            x+=i.second%2;
        }
        
        if(x>1)
            return false;
        return true;
    }
    void dfs(TreeNode *root,unordered_map<int,int>&mp,int&ans)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr&&root->right==nullptr)
        {
            mp[root->val]++;
            if(pos(mp))
                ans++;
            mp[root->val]--;
            return;
        }
        mp[root->val]++;
        dfs(root->left,mp,ans);
        dfs(root->right,mp,ans);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        int ans=0;
        dfs(root,mp,ans);
        
        return ans;
    }
};