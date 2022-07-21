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
    int widthOfBinaryTree(TreeNode* root) {
        
        
        long long mx =0;
        
        if(root==nullptr)
            return 0;
        
        int cnt=0;
        
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        
        //int mx = 0;
        while(q.size())
        {
            int n = q.size();
            
            //int mn = q.front()
            
            long long mnLevel =INT_MAX;
            long long mxLevel = 0;
            for(int i=0;i<n;i++)
            {
//cout<<1<<endl;
                auto currNodeP = q.front();
                q.pop();
                
                TreeNode*curr = currNodeP.first;
                long long ind = currNodeP.second;
                
                if(i==0)
                {
                    mnLevel = min(mnLevel,ind);
                    
                }
                 
                mxLevel = max(mxLevel,ind);
                ind =ind-mnLevel;
                
                
                
                 if(curr->left)
                 {
                     int k = 2*ind+1;
                     q.push({curr->left,k});
                 }
                
                if(curr->right)
                {
                    int k = 2*ind+2;
                    q.push({curr->right,k});
                }
                
            
            }
            
            mx = max(mx,mxLevel-mnLevel+1);
        }
        
        return mx;
    }
};