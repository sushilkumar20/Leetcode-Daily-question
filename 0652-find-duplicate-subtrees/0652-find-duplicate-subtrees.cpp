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
    map<string,int> mp;
    string preorder(TreeNode *root, vector<TreeNode*> &arr)
    {
        if(root== nullptr)
            return "";
        
       // s+=to_string(root->val);
        
        
        //st.insert(s);
       string leftS = preorder(root->left,arr);
       string rightS = preorder(root->right,arr);
        
        //cout<<s<<endl;
        string s = to_string(root->val)+"l"+leftS+"r"+rightS;
        
        //cout<<s<<endl;
         if(mp.find(s) !=mp.end()&&mp[s]==1)
            arr.push_back(root);
        
        mp[s]++;
        
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       
        vector<TreeNode*> arr;
        
        string s ="";
        preorder(root,arr);
        
        return arr;
    }
};