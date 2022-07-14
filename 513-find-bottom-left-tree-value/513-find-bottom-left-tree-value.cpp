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
    int findBottomLeftValue(TreeNode* root) {
        
        int x=-1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode *node =q.front();
                q.pop();
                
                if(i==0)
                    x=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        
        return x;
    }
};