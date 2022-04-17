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
    void inorder(TreeNode *root,vector<int>&arr)
    {
        if(root==nullptr)
            return ;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        
       vector<int> arr;
        
        inorder(root,arr);
        
        if(arr.size()==0)
            return nullptr;
        TreeNode *root1 =new TreeNode();
        
        TreeNode *p=root1;
        for(int i=0;i<arr.size();i++)
        {
            p->val=arr[i];
            TreeNode *q =new TreeNode();
            if(i!=arr.size()-1)
            p->right =q;
            
            p=q;
        }
        
        return root1;
        
    }
};