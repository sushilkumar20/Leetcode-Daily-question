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
    
    TreeNode*construct(int &ind, vector<int>&preorder,map<int,int>&mp,vector<int>&inorder,int low, int high)
    {
        if(low>high||ind>preorder.size())
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[ind]);
        int mid = mp[preorder[ind]];
        ind++;
        
        root->left=construct(ind,preorder,mp,inorder,low,mid-1);
        root->right=construct(ind,preorder,mp,inorder,mid+1,high);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        
        int ind =0;
        
        return construct(ind, preorder,mp,inorder,0,inorder.size()-1);
    }
};