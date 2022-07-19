/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preorder(Node*root, vector<int> &ans)
    {
        if(root==nullptr)
            return;
        
        ans.push_back(root->val);
        vector<Node*> children = root->children;
        
        for(int i=0;i<children.size();i++)
        {
            preorder(children[i],ans);
        }
        
    }
    vector<int> preorder(Node* root) {
        
        vector<int> ans;
        
        preorder(root,ans);
        
        return ans;
    }
};