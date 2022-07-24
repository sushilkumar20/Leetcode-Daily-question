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
    TreeNode* construct(int low,int high,map<int,int>&mp,vector<int>& preorder,int &i)
    {
        if(low>high||i>preorder.size())
            return nullptr;
        
        TreeNode *root  =new TreeNode(preorder[i]);
        
        int mid = mp[preorder[i]];
        i++;
        root->left = construct(low,mid-1,mp,preorder,i);
        root->right = construct(mid+1,high,mp,preorder,i);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        int i=0;
        return construct(0,inorder.size()-1,mp,preorder,i);
    }
};