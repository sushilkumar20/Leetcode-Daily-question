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
    int dfs(TreeNode* root, int &mx)
    {
        if(root == nullptr)
        {
            return 0;
        }
        
        int l1 = dfs(root->left,mx);
        int r1 = dfs(root->right,mx);
        
       // cout<<l1<<" "<<r1<<" "<<root->val<<endl;
         mx = max(mx,l1+r1+1);
       
        return max(l1,r1)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int mx=0;
        
        dfs(root,mx);
        
      
        
        return mx-1;
    }
};