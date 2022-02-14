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
    void dfs(TreeNode* root,int &ans,int &curr)
    {
      if(root==nullptr)
      {
          ans=max(ans,curr);
          return;
      }
        
        curr++;
        dfs(root->left,ans,curr);
        dfs(root->right,ans,curr);
        
        curr--;
    }
    int maxDepth(TreeNode* root) {
        
        int ans=0;
        int curr=0;
        dfs(root,ans,curr);
        
        return ans;
    }
};