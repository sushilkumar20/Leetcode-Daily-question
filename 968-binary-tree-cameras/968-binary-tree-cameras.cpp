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
    int minCameraCover(TreeNode* root) {
       set<TreeNode*> st;
        int ans=0;
        st.insert(nullptr);
        
        dfs(root,st,ans,nullptr);
        
        return ans;
    }
    
    void dfs(TreeNode* root, set<TreeNode*> &st, int &ans, TreeNode* par)
    {
        if(root==nullptr)
            return;
        
        dfs(root->left,st,ans,root);
        dfs(root->right,st,ans,root);
        
        if(par==nullptr&&st.find(root)==st.end()||st.find(root->left)==st.end()||st.find(root->right)==st.end())
        {
            ans++;
            
            st.insert(root);
            st.insert(root->left);
            st.insert(root->right);
            st.insert(par);
        }
    }
};