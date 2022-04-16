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
    TreeNode *help(TreeNode * root, int &x)
    {
        
        
         if(root ==nullptr)
            return nullptr;
        if(root->left ==nullptr&&root->right==nullptr)
        {
            TreeNode *p=new TreeNode(x+root->val);
            x+=root->val;
             //cout<<x<<endl;
            return p;
        }
        
        TreeNode *p =new TreeNode();
        p->right=help(root->right,x);
        
        x+=root->val;
       
        p->val=x;
        
        p->left =help(root->left,x);
        
        return p;
        
        
    }
    TreeNode* convertBST(TreeNode* root) {
        
        int x=0;
       return help(root,x);
    }
};