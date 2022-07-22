/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode*p, vector<TreeNode*> &arr)
    {
        if(root==nullptr)
            return false;
        
        if(root==p)
        {
            arr.push_back(root);
            return true;
        }
        
        arr.push_back(root);
        bool kk = dfs(root->left,p,arr);
        bool ok = dfs(root->right,p,arr);
        
        if(!ok&&!kk)
        {
            arr.pop_back();
            return false;
        }
        
        return true;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> arr1;
        vector<TreeNode*> arr2;
        
        bool ok1 =dfs(root,p,arr1);
        bool ok2=dfs(root,q,arr2);
        
        if(!ok1||!ok2)
            return nullptr;
        //cout<<arr1.size()<<" "<<arr2.size()<<endl;
        TreeNode *temp=nullptr;
        for(int i=0;i<min((int)arr1.size(),(int)arr2.size());i++)
        {
            if(arr1[i]!=arr2[i])
                break;
            temp=arr1[i];
        }
        
        return temp;
    }
};