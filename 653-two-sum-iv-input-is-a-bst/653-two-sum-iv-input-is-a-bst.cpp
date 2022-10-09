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
   bool find(TreeNode *root, int k, map<int,int>&mp)
    {
        if(root==nullptr)
            return false;
        
        int x = k-root->val;
        
        if(mp.find(x)!=mp.end())
            return true;
        
        mp[root->val]++;
        
        if(find(root->left,k,mp)||find(root->right,k,mp))
            return true;
        
        return false;
        
    }
    bool findTarget(TreeNode* root, int k) {
        
        map<int,int> mp;
        
       return find(root,k,mp);
    }
};