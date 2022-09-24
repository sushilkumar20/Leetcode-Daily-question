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
    vector<int> arr;
    vector<vector<int>> ans;
    int sum=0;
     bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==nullptr)
            return false;
         sum+=root->val;
         arr.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr)
        {
            if(sum==targetSum){
                ans.push_back(arr);
                arr.pop_back();
                sum-=root->val;
                return false;
            }
            else{
                sum-=root->val;
                arr.pop_back();
                return false;
            }
        }
        
        //cout<<sum<<endl;
        
        bool left=hasPathSum(root->left, targetSum);
        bool right=hasPathSum(root->right, targetSum);
        
        if(left==false&&right==false){
            arr.pop_back();
            sum-=root->val;
        }
       
        //cout<<sum<<endl;
        
         
         return left||right;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        hasPathSum( root, targetSum);
        
        return ans;
    }
};