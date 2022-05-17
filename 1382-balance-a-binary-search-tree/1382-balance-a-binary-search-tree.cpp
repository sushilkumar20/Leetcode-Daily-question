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
    
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if(root==nullptr)
            return ;
        
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
    TreeNode *bst(vector<int> arr, int low, int high)
    {
        if(low<=high)
        {
            int mid = (low+high)/2;
            
            TreeNode * root = new TreeNode(arr[mid]);
            root->left = bst(arr,low,mid-1);
            root->right = bst (arr, mid+1, high);
            
            return root;
        }
        
        return nullptr;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> arr;
        
        inorder(root,arr);
        
        TreeNode *root1 ;
        
        return bst(arr, 0, arr.size()-1);
        
        
    }
};