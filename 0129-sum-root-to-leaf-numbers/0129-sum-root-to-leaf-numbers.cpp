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
    
    int sum=0;
    void preorder(TreeNode* root,string s)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr&&root->right==nullptr)
        {
          
           
                sum+=stoi(s+to_string(root->val));
                //cout<<s<<endl;
                
            
            return ;
        }
       
        
        s+=to_string(root->val);
        
        preorder( root->left,s);
         preorder( root->right,s);
    }
    int sumNumbers(TreeNode* root) {
        preorder(root,"");
        
        return sum;
    }
};