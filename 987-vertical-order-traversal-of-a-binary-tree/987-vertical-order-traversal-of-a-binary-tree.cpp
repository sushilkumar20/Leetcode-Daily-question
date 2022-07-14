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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        map<int,vector<int>> mp;
        
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        
        while(q.size())
        {
            int n=q.size();
            
            map<int,vector<int>> mp1;
            for(int i=0;i<n;i++)
            {
                auto x =q.front();
                q.pop();

                int ind = x.first;
                TreeNode *p = x.second;

                mp1[ind].push_back(p->val);
                if(p->left)
                {
                    q.push({ind-1,p->left});
                }

                 if(p->right)
                {
                    q.push({ind+1,p->right});
                }
            }
            
            for(auto &i:mp1)
            {
                  sort(i.second.begin(),i.second.end());
                for(int j=0;j<i.second.size();j++){
                  mp[i.first].push_back(i.second[j]);
                }
            }
          
        }
        
        for(auto &i:mp)
        {
           // sort(i.second.begin(),i.second.end());
            ans.push_back(i.second);
        }
        
        return ans;
    }
};