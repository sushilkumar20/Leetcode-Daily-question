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
            return;
        
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> arr;
        
          inorder(root1,arr);
        
         vector<int> brr;
         inorder(root2,brr);
        
        vector<int> crr;
        
        int i=0;
        int j=0;
        
        while(i<arr.size()&&j<brr.size())
        {
            if(arr[i]<brr[j])
            {
                crr.push_back(arr[i]);
                i++;
            }
            else
            {
                crr.push_back(brr[j]);
                j++;
            }
        }
        
         while(i<arr.size())
        {
                crr.push_back(arr[i]);
             i++;
           
        }
        
        while(j<brr.size())
        {
                crr.push_back(brr[j]);
            j++;
           
        }
        
        return crr;
        
    }
};