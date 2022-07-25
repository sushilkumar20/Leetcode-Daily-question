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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        
        auto k = st.top();
        st.pop();
        
        int ans = k->val;
        
        if(k->right)
        {
            //st.push(k->right);
            
            k=k->right;
            
            while(k)
            {
                st.push(k);
                k=k->left;
            }
        }
        
        return ans;
        
        
    }
    
    bool hasNext() {
        
        if(st.size())
            return true;
        
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */