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
class BSTIterator{
    public:
    stack<TreeNode*> st;
    bool reverse;
    
    BSTIterator(TreeNode *root, bool reverse)
    {
        this->reverse = reverse;
        pushAll(root);
    }
    
    bool hasNext()
    {
        return st.size();
    }
    
    int next()
    {
        TreeNode *top=st.top();
        st.pop();
        int k=top->val;
        
        if(reverse)
        {
            if(top->left)
            {
                pushAll(top->left);
            }
        }else
        {
            if(top->right)
            {
                pushAll(top->right);
            }
        }
        
        return k;
    }
    
    void pushAll(TreeNode *root)
    {
        while(root)
        {
            st.push(root);
            if(reverse)
                root=root->right;
            else
                root=root->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
       // map<int,int> mp;
        
        BSTIterator *l = new BSTIterator(root,false);
        BSTIterator *r = new BSTIterator(root,true);
        
        int i= l->next();
        int j= r->next();
        //cout<<i<<" "<<j<<endl;
        while(i<j)
        {
           // cout<<i<<" "<<j<<endl;
            if(i+j==k)
                return true;
            else if(i+j>k)
            {
                j=r->next();
            }
            else
            {
                i=l->next();
            }
        }
        
       return false;
    }
};