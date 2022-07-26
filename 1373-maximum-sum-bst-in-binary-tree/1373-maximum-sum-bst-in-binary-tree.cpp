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
class node{
    public:
    int mx;
    int mn;
    int size;
    int sum ;
    node(int mx, int mn, int size,int sum)
    {
        this->mx = mx;
        this->mn = mn;
        this->size = size;
        this->sum = sum;
    }
};
class Solution {
public:
    node *find(TreeNode*root, int&mx)
    {
        if(root==nullptr)
        {
            return new node(INT_MIN,INT_MAX,0,0);
        }
        
        auto left = find(root->left,mx);
        auto right = find(root->right,mx);
        
        
        if(root->val>left->mx&&root->val<right->mn)
        {
           // cout<<root->val<<" "<<left->sum<<" "<<right->sum<<endl;
            mx=max(mx,root->val+left->sum+right->sum);
            return new node(max(root->val,right->mx),min(root->val,left->mn),left->size+right->size+1,root->val+left->sum+right->sum);
        }
        
        return new node(INT_MAX,INT_MIN,max(left->size,right->size),0);
    }
    int maxSumBST(TreeNode* root) {
        
        int mx = 0;
        
        find(root,mx);
        return mx;
    }
};