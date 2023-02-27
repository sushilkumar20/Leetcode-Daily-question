//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
        // code here
        if(head==nullptr||head->next==nullptr)
        return head;
        
        Node *p=head;
        Node *q=nullptr;
        Node *r=head->next;
        
        int xx =k;
        while(p!=nullptr&&xx>0)
        {
            p->next = q;
            q=p;
            p=r;
            if(r!=nullptr)
            r=r->next;
            xx--;
        }
        
        if(r==nullptr)
        {
            return p;
        }
        
        Node *x = q;
       
        // p=r;
        q=nullptr;
        // r=r->next;
        
        while(p!=nullptr)
        {
            p->next = q;
            q=p;
            p=r;
            if(r!=nullptr)
            r=r->next;
        }
        
        head->next = q;
        
        return x;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends