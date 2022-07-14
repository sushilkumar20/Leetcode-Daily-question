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
    TreeNode* construct(vector<int>& preorder,int &ps, vector<int>&inorder, int is, int ie,map<int,int> &mp)
    {
        if(is>ie||ps>=preorder.size())
            return nullptr;
        
        TreeNode * root = new TreeNode(preorder[ps]);
        
        int k=mp[preorder[ps]];
        
       // int fromStartInorder = k-is;
        ps++;
        root->left = construct(preorder,ps,inorder,is,k-1,mp);
      //  ps++;
        root->right = construct(preorder,ps,inorder,k+1,ie,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size()!=inorder.size())
            return nullptr;
        
        int n = inorder.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        
        int i=0;
        return construct(preorder,i,inorder,0,inorder.size()-1,mp);
    }
};