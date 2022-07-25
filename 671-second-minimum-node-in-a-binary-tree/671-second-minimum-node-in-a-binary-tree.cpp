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
    void inorder(TreeNode* root,set<int> &st)
    {
       if(root==nullptr)
           return;
        
        inorder(root->left,st);
        st.insert(root->val);
        inorder(root->right,st);
    }
    int findSecondMinimumValue(TreeNode* root) {
        
       set<int>st;
       
        inorder(root,st);
        
        if(st.size()<2)
            return -1;
        
        st.erase(st.begin());
        
        return*st.begin();
    }
};