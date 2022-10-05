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
    TreeNode* help(int currDepth, int depth,TreeNode* root, int val)
    {
        if(root==nullptr)
            return nullptr;
        
        if(currDepth==depth-1)
        {
            //cout<<1<<endl;
             TreeNode * newNodeleft = new TreeNode(val);
             newNodeleft->left=root->left;
            
             TreeNode * newNoderight = new TreeNode(val);
             newNoderight->right=root->right;
            
            root->left = newNodeleft;
            root->right = newNoderight;
            
            return root;
        }
        
         help(currDepth+1,depth,root->left,val);
         help(currDepth+1,depth,root->right,val);
        
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1)
        {
            TreeNode * newNode = new TreeNode(val);
            
            newNode->left = root;
            
            return newNode;
        }
        
         help(1,depth,root,val);
        
        return root;
    }
};