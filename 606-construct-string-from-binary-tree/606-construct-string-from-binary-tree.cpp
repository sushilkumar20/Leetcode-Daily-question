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
    void preorder(TreeNode* root, string &ans)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr&&root->right==nullptr)
        {
            ans+=to_string(root->val);
            return;
        }
        ans+= to_string(root->val);
        
        ans+="(";
        preorder(root->left,ans);
        ans+=")";
        
        
        if(root->right!=nullptr)
        {
        ans+="(";
        preorder(root->right,ans);
        ans+=")";
        }
    }
    string tree2str(TreeNode* root) {
        
        string ans="";
        
        preorder(root,ans);
        return ans;
    }
};