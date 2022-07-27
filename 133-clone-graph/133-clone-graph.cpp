/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        map<Node*,Node*> mp;
        if(node==nullptr)
            return nullptr;
        queue<Node*> q;
        q.push(node);
        
        Node* root = new Node(node->val);
        mp[node] = root;
        //Node*curr;
        while(q.size())
        {
            Node* p= q.front();
            q.pop();
            
            for(auto i:p->neighbors)
            {
                if(mp.find(i)==mp.end())
                {
                    Node *newNode = new Node(i->val);
                    mp[i] = newNode;
                    mp[p]->neighbors.push_back(newNode);
                    q.push(i);
                    
                }
                else
                {
                     mp[p]->neighbors.push_back(mp[i]);
                }
            }
        }
        
        return root;
    }
};