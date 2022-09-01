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
    
    void dfs(TreeNode* root, int h, int &cnt)
    {
        if(root==nullptr)
            return;
        
        if(root->val>=h)
            cnt++;
        dfs(root->left,max(h,root->val),cnt);
        dfs(root->right,max(h,root->val),cnt);
    }
    int goodNodes(TreeNode* root) {
        
        int cnt=0;
        int h = -1e9;
        
        dfs(root,h,cnt);
        
        
        return cnt;
    }
};