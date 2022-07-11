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
    vector<int> rightSideView(TreeNode* root) {
        
        
            
        vector<int> ans;
        
        if(root==nullptr)
            return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.size())
        {
            int k= q.size();
            vector<int> arr;
            for(int i=0;i<k;i++)
            {
                TreeNode* x = q.front();
                q.pop();
                arr.push_back(x->val);
                if(x->left!=nullptr)
                    q.push(x->left);
                if(x->right!=nullptr)
                    q.push(x->right);
                    
            }
            
                if(arr.size())
                ans.push_back(arr.back());
        }
        
        return ans;
    }
};