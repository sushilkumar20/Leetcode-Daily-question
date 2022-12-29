//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    TNode* sortedListToBST(LNode *head) {
        //code here
        if(head == nullptr)
        {
            return nullptr;
        }
        
        if(head->next == nullptr)
        {
            TNode *nwNode = new TNode(head->data);
            
            return nwNode;
        }
        
        LNode *rgt = head;
        LNode *p = head;
        LNode *prv  = rgt;
        while(p!=nullptr&&p->next!=nullptr)
        {
            prv=rgt;
            rgt=rgt->next;
            p=p->next;
            if(p)
            p=p->next;
        }
        
        TNode *root = new TNode(rgt->data);
        LNode *tmp = rgt->next;
        prv->next = nullptr;
        if(rgt!=prv)
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(tmp);
       
       
        // rgt->next = tmp;
       
        
        return root;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends