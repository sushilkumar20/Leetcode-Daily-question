/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        map<Node*,Node*> mp;
        
        Node *dummy = new Node(0);
        Node *curr = dummy;
        Node *p = head;
        
        while(p != nullptr)
        {
            Node *temp = new Node(p->val);
            mp[p]=temp;
            
            curr->next = temp;
            curr=temp;
            p=p->next;
            
        }
        
        p=head;
        
        while(p!=nullptr)
        {
            mp[p]->random = mp[p->random];
            p=p->next;
        }
        
        return dummy->next;
    }
};