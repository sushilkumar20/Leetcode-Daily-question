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
    void preorder(TreeNode* root, vector<int> &arr)
    {
        if(root==nullptr)
            return;
        
        arr.push_back(root->val);
        preorder(root->left,arr);
        preorder(root->right,arr);
    }
    
    
    vector<int> preorderTraversal(TreeNode* root) {
       
        stack<TreeNode*> st;
        
        vector<int> ans;
        
        while(root!=nullptr||st.size())
        {
           if(root!=nullptr)
           {
               ans.push_back(root->val);
               st.push(root);
               root=root->left;
              
           }
            else
            {
               root=st.top();
                st.pop();
                root=root->right;
            }
        }
        
        return ans;
    }
};