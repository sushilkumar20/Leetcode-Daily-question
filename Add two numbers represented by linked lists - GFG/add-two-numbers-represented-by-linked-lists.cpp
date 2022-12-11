//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* revrse(struct Node *head)
    {
        if(head==nullptr||head->next == nullptr)
        return head;
        
        
        Node *curr = head;
        Node *prv = nullptr;
        Node *nxt = curr->next;
        
        while(curr != nullptr)
        {
            curr->next = prv;
            prv = curr;
            curr = nxt;
            if(nxt)
            nxt = nxt->next;
        }
        
        return prv;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *rfirst = revrse(first);
        Node *rsecond = revrse(second);
        
        // cout<<rfirst->data<<endl;
        // cout<<rsecond->data<<endl;
        int c = 0;
        
        Node *shead = new Node(0);
        Node*curr =shead;
        while(rfirst!=nullptr&&rsecond!=nullptr)
        {
            int sum = rfirst->data + rsecond->data+c;
            
           
            c = sum/10;
            
            curr->next = new Node(sum%10);
            curr = curr->next;
            
            rfirst = rfirst->next;
            rsecond = rsecond->next;
        }
        
         while(rfirst!=nullptr)
        {
            int sum = rfirst->data +c;
            
            c = sum/10;
            
            curr->next = new Node(sum%10);
            curr = curr->next;
            
            rfirst = rfirst->next;
            
        }
        
         while(rsecond!=nullptr)
        {
            int sum =  rsecond->data+c;
            
            c = sum/10;
            
            curr->next = new Node(sum%10);
            curr = curr->next;
            
           
            rsecond = rsecond->next;
        }
        
        if(c>0)
        {
            curr->next = new Node(c);
            curr = curr->next;
        }
        
        return revrse(shead->next);
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends