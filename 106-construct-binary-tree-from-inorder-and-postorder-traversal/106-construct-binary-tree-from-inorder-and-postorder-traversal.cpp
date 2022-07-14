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
    
    TreeNode *construct(vector<int>& inorder, int start, int end, vector<int>& postorder, int&i,  map<int,int> &mp)
    {
        if(i<0||start>end){
           // cout<<start<<" "<<end<<" "<<i<<endl;
            return nullptr;
        }
        
        int k=mp[postorder[i]];
        TreeNode* root = new TreeNode(postorder[i]);
        i--;
        
        
        root->right =construct(inorder,k+1,end,postorder,i,mp);
           
        root->left = construct(inorder,start,k-1,postorder,i,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=inorder.size();
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        int i=n-1;
        return construct(inorder,0,inorder.size()-1,postorder,i,mp);
    }
};