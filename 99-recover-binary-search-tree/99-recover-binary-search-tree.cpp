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
    
    void inorder(TreeNode* root, vector<int> &arr)
    {
        if(root==nullptr)
            return;
        
       inorder(root->left,arr);
       arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
    void inorder1(TreeNode* root, vector<int> &arr,int &i)
    {
        if(root==nullptr)
            return ;
        inorder1(root->left,arr,i);
        root->val =arr[i];
        i++;
        inorder1(root->right,arr,i);
        
       
    }
    void recoverTree(TreeNode* root) {
        
        vector<int> arr;
        
        inorder(root,arr);
        
        vector<int> brr=arr;
        sort(brr.begin(),brr.end());
        
        int x=0;
         inorder1(root,brr,x);
    }
};