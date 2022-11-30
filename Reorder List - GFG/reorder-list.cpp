//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:

     Node* reverse(Node *head)
     {
         Node *p = head;
         Node *q = nullptr;
         
         while(p!=nullptr)
         {
             Node*temp = p->next;
             p->next = q;
             
             q=p;
             p = temp;
         }
         
         return q;
     }
    void reorderList(Node* head) {
        // Your code here
        int cnt =0 ;
        
        Node *p= head;
        
        while(p!=nullptr)
        {
            cnt++;
            p=p->next;
        }
        
         cnt = cnt/2;
        
        p=head;
        
        Node* q1 = nullptr;
        while(cnt>0)
        {
            q1=p;
            p=p->next;
            cnt--;
        }
        
        if(q1!=nullptr)
        q1->next = nullptr;
        
        Node * q = reverse(p);
        
        p = head;
        
        cnt = 0;
        
        // cout<<p->data<<" "<<q->data<<endl;
        
        while(p!=nullptr&&q!=nullptr)
        {
            // cout<<p->data<<" "<<q->data<<endl;
            Node*temp = p->next;
            Node *temp1 = q->next;
            p->next = q;
            q->next = temp;
            
            p=temp;
            q=temp1;
        }
        
        Node *p1 = head;
        
        while(p1->next)
        {
            p1=p1->next;
        }
        
        if(p)
        {
            p1->next = p;
        }
        
        if(q)
        {
            p1->next=q;
        }
    
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends