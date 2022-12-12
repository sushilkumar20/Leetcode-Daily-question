//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node* arr[], int lw, int hg)
    {
        if(lw<hg)
        {
            
             int mid = (lw+hg)/2;
            
            Node *left = merge(arr,lw,mid);
            Node *right = merge(arr,mid+1,hg);
            
            Node *head = new Node(0);
            Node *curr = head;
            while(left!=nullptr&&right!=nullptr)
            {
                
                if(left->data<right->data)
                {
                    curr->next = left;
                    left = left->next;
                    curr=curr->next;
                }
                else
                {
                    curr->next = right;
                    right = right->next;
                    curr=curr->next;
                }
            }
            
            if(left != nullptr)
            curr->next = left;
            
            if(right != nullptr )
            curr->next = right;
            
            
            return head->next;
            
        }
        else if(lw == hg){
            
        return arr[lw];
        }
        return nullptr;
       
    }
    
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           
           return merge(arr,0,K-1);
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends