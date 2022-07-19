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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<pair<TreeNode*,int>> st;
        vector<int> ans;
        while(st.size()||root)
        {
            //cout<<root->val<<endl;
            if(root!=nullptr)
            {
                st.push({root,1});
                root=root->left;
            }
            else
            {
                pair<TreeNode*,int> pr =st.top();
                st.pop();
                if(pr.second==2)
                {
                    ans.push_back(pr.first->val);
                    root=nullptr;
                }
                else
                {
                    root=pr.first->right;
                    st.push({pr.first,2});
                }
            }
        }
        
        return ans;
    }
};