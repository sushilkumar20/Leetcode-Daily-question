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
//     void dfs(Node* root, int i, map<int,vector<int>>&mp)
//     {
//         if(root==nullptr)
//             return;
        
//         mp[i].push_back(root->val);
//         dfs(root)
//     }
    vector<vector<int>> levelOrder(Node* root) {
       
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        queue<Node*> q;
        
        q.push(root);
        
        while(q.size())
        {
            int n=q.size();
            vector<int> arr;
            for(int i=0;i<n;i++)
            {
                auto u = q.front();
                arr.push_back(u->val);
                q.pop();
                
                for(auto v:u->children)
                {
                    q.push(v);
                }
            }
            if(arr.size())
            ans.push_back(arr);
        }
        
        return ans;
    }
};