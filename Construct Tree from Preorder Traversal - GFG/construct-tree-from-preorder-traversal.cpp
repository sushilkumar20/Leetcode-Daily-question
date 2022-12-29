//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
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

void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

Node* constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends


/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    stack<pair<Node*,int>> st;
    vector<Node*> arr;
    
    for(int i=0;i<n;i++)
    {
        if(preLN[i]=='N')
        {
            Node *nw = new Node(pre[i]);
            
            if(st.size())
            {
                if(st.top().second == 0)
                {
                    st.top().first->left = nw;
                    st.top().second++;
                }
                else
                {
                    st.top().first->right = nw;
                    arr.push_back(st.top().first);
                    st.pop();
                }
            }
            st.push({nw,0});
        }
        else
        {
            Node *nw = new Node(pre[i]);
            
            if(st.size())
            {
                if(st.top().second == 0)
                {
                    st.top().first->left = nw;
                    st.top().second++;
                }
                else
                {
                    st.top().first->right = nw;
                    arr.push_back(st.top().first);
                    st.pop();
                }
            }
            
            if(n==1)
            return nw;
        }
    }
    
    // cout<<arr.back()->data<<endl;
    
    Node *tmp = arr[0];
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]->data == pre[0])
        return arr[i];
    }
    
    return tmp;
}