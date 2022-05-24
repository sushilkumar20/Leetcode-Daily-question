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
    void dfs(TreeNode *root, int cnt, vector<vector<int>>&arr)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr&&root->right==nullptr)
        {
            arr.push_back(vector<int>{cnt,root->val});
            return;
        }
       
        dfs(root->left,cnt+1,arr);
        dfs(root->right,cnt+1,arr);
    }
    int deepestLeavesSum(TreeNode* root) {
        
        vector<vector<int>> arr;
        int cnt=0;
        dfs(root,cnt,arr);
        
        sort(arr.rbegin(),arr.rend());
        
        int sum=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i][0]==arr[0][0])
                sum+=arr[i][1];
            else
                break;
        }
        
        return sum;
    }
};