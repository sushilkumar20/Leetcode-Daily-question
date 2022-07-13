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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root==nullptr)
            return ans;
        queue<TreeNode*> q;
        
        if(root)
        q.push(root);
        
        while(q.size()!=0)
        {
            vector<int> arr;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
            TreeNode *k=q.front();
            q.pop();
            arr.push_back(k->val);
            if(k->left)
                q.push(k->left);
            if(k->right)
                q.push(k->right);
                
            }
            
            ans.push_back(arr);
            
            
        }
        
        return ans;
    }
};