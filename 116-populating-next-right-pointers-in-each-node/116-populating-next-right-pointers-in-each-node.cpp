/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> q;
        if(root==nullptr)
            return root;
        q.push(root);
            
        while(q.size())
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                //cout<<q.front()->val<<" ";
                Node* k= q.front();
                q.pop();
                if(i!=n-1)
                {
                    k->next = q.front();
                    //continue;
                }
                
               
                
                if(k->left)
                    q.push(k->left);
                
                if(k->right)
                    q.push(k->right);
            }
           // cout<<endl;
           // q.pop();
        }
        
        return root;
    }
};