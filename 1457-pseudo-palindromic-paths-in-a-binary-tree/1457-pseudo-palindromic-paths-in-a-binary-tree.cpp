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
    bool pos(vector<int> &arr)
    {
        int x=0;
        for(int i=0;i<10;i++)
        {
            x+=arr[i]%2;
        }
        
        if(x>1)
            return false;
        return true;
    }
    void dfs(TreeNode *root,vector<int>&arr,int&ans)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr&&root->right==nullptr)
        {
            arr[root->val]++;
            if(pos(arr))
                ans++;
            arr[root->val]--;
            return;
        }
        arr[root->val]++;
        dfs(root->left,arr,ans);
        dfs(root->right,arr,ans);
        arr[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> arr(10,0);
        int ans=0;
        dfs(root,arr,ans);
        
        return ans;
    }
};