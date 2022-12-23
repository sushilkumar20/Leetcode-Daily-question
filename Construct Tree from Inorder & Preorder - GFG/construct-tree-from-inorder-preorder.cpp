//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int find(int in[], int lw, int hg, int x)
    {
        for(int i=lw;i<=hg;i++)
        {
            if(in[i]==x)
            return i;
        }
        
        return -1;
    }
    Node *create(int &pInd, int iS, int iE,int in[], int pre[], int n)
    {
        if(iS<=iE)
        {
            int x = pre[pInd];
           
            Node *node = new Node(pre[pInd]);
            int md = find(in,iS,iE,x);
            // cout<<md<<endl;
             pInd++;
            node->left = create(pInd,iS,md-1,in,pre,n);
            node->right = create(pInd,md+1,iE,in,pre,n);
            
            return node;
        }
        
        return nullptr;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int pInd = 0;
        int iS =0;
        int iE = n-1;
        
        return create(pInd,iS,iE,in,pre,n);
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends