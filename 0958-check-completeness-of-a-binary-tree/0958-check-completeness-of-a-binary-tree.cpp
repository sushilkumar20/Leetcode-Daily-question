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
    bool isCompleteTree(TreeNode* root) {
        
        if(root==nullptr)
            return 1;
        queue<TreeNode*> q;
        
        q.push(root);
        
        // arr.push_back(root->val);
        bool ok1=0;
        while(q.size())
        {
            
            int z = q.size();
            
            int cnt = 0;
            
            bool ok=0;
            for(int i=0;i<z;i++)
            {
                 auto frt = q.front();
                q.pop();
                
                if(frt->left)   
                {
                    if(ok)
                        return 0;
                    cnt++;
                    q.push(frt->left);
                }
                else
                    ok=1;
                
                if(frt->right)   
                {
                    if(ok)
                        return 0;
                    cnt++;
                    q.push(frt->right);
                }
                else
                    ok=1;
            }
            
           if(ok1&&q.size())
                   return 0;
            
            if(ok)
            {
               if(ok1&&q.size())
                   return 0;
                
                if(q.size())
                {
                    ok1=1;
                }
            }
            else
            {
                
                if(cnt!=2*z){
                    // cout<<z<<" "<<cnt<<endl;
                    return 0;
                }
            }
            
        }
        
        return 1;
    }
};