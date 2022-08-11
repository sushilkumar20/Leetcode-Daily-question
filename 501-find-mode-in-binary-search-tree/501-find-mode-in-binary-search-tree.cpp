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
    void preorder(TreeNode*root, map<int,int> &mp,int&mx)
    {
        if(root==nullptr)
            return ;
        
        mp[root->val]++;
        mx=max(mx,mp[root->val]);
        
        preorder(root->left,mp,mx);
        preorder(root->right,mp,mx);
        
        
        
    }
    vector<int> findMode(TreeNode* root) {
        
        map<int,int> mp;
        
        vector<int> ans;
        
        int mx=0;
        preorder(root,mp,mx);
        
        for(auto i:mp)
        {
            if(i.second==mx)
                ans.push_back(i.first);
        }
        return ans;
    }
};