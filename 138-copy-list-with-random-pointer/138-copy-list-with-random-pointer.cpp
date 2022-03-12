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
        
        if(head==nullptr)
            return head;
        Node*p=head;
        
        Node  *t=new Node(head->val);
        t->next=p->next;
        p->next=t;
        p=t->next;
        while(p!=nullptr)
        {
            t=new Node(p->val);
            
            t->next=p->next;
            p->next=t;
            p=t->next;
            
        }
        
        p=head;
        
        while(p!=nullptr)
        {
            if(p->random!=nullptr)
            p->next->random=p->random->next;
            p=p->next->next;
        }
        
        
       Node *q=new Node(0);
       Node *r=head;
        
       Node * head1=q;
        
      
        while(r!=nullptr)
        {
            q->next=r->next;
            r->next=r->next->next;
            r=r->next;
            q=q->next;
        }
        
        return head1->next;
    }
};