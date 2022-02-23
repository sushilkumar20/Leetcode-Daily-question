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
        
        if(node==nullptr)
            return nullptr;
        Node *root = new Node();
        map<int,Node*> mp;
        
        queue<Node*> q;
        
          q.push(node);
          Node *nw=new Node(node->val);
        
         root=nw;
        
         mp[node->val]=nw;
        int i=0;
        while(q.size()!=0)
        {
            Node*p=q.front();
            q.pop();
            
            
          
            //mp[p->val]=nw;
            //cout<<p->val<<endl;
           
           
            
            for(int i=0;i<p->neighbors.size();i++)
            {
                if(mp.find(p->neighbors[i]->val)==mp.end())
                {
                   
                     Node *nw1= new Node(p->neighbors[i]->val);
                     mp[p->neighbors[i]->val]=nw1;
                     q.push(p->neighbors[i]);
                }
                
               // cout<<p->val<<" "<<p->neighbors[i]->val<<endl;
                
                mp[p->val]->neighbors.push_back(mp[p->neighbors[i]->val]);
            }
        }
        
        return root;
        
        
    }
};