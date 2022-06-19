// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        
        while(head==nullptr||head->next==nullptr)
        return head;
        if(m==n)
        return head;
        Node*p=head;
        Node*q=nullptr;
        Node*r=head->next;
        int cnt=0;
        
        Node*first=nullptr;
        Node*second=nullptr;
        
        while(p!=nullptr)
        {
            cnt++;
            if(cnt==m)
            {
                first=q;
            }
            else if(cnt==n)
            {
                second=r;
            }
            
            q=p;
            p=p->next;
            if(r!=nullptr)
            r=r->next;
        }
        //cout<<second->data<<endl;
        p=head;
        q=nullptr;
        r=head->next;
        cnt=0;
        while(p!=nullptr)
        {
            cnt++;
            
            if(cnt>=m)
            {
                
               // cout<<p->data<<endl;
            //   cout<<cnt<<endl;
            //   break;
                if(cnt==m)
                {
                    p->next=second;
                    q=p;
                    p=r;
                     if(r)
                    r=r->next;
                    
                }
                else if(cnt==n)
                {
                    if(m==1)
                    head=p;
                    if(first)
                    {
                        first->next=p;
                    }
                    p->next=q;
                    q=p;
                    p=r;
                    if(r)
                    r=r->next;
                    break;
                }
                else
                {
                    p->next=q;
                    q=p;
                    p=r;
                    if(r)
                    r=r->next;
                }
                
                
            }
            else
            {
             q=p;
             p=p->next;
             if(r!=nullptr)
             r=r->next;
            }
        }
        
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends