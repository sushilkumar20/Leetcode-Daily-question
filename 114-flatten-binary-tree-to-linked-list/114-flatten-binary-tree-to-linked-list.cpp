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
    
    void preorder(TreeNode* root,vector<int>&arr)
    {
        if(root==nullptr)
            return;
        
        arr.push_back(root->val);
        
        preorder(root->left,arr);
        preorder(root->right,arr);
        
    }
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return;
        vector<int> arr;
       //reeNode *root1 = new TreeNode();
        preorder(root, arr);
        
        root->left = nullptr;
        
        TreeNode *curr = root;
        for(int i=1;i<arr.size();i++)
        {
            curr->right = new TreeNode(arr[i]);
            
            curr=curr->right;
        }
        
        
    }
};