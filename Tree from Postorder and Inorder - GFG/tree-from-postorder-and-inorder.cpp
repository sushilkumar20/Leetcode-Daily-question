//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

int i;

Node* build(int l, int j, int in[], int post[])
{
    if(l<=j)
    {
        Node *root = new Node(post[i]);
       
        
        int mid = -1;
        
        for(int x =l;x<=j;x++)
        {
            if(in[x]==post[i]){
            mid = x;
            break;
            }
        }
        
        // cout<<post[i]<<" "<<mid<<endl;
        if(mid == -1)
        return nullptr;
        i--;
        Node* right = build(mid+1,j,in,post);
        Node *left = build(l,mid-1,in,post);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    return nullptr;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    
    i=n-1;
    
    return build(0,n-1,in,post);
}
