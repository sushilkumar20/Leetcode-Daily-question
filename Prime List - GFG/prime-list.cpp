//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    
    vector<int> arr;
    bool isPrime(int n)
    {
        if(n<2)
        return 0;
        for(int j=2;j*j<=n;j++)
        {
            if(n%j==0)
            return 0;
        }
        
        return 1;
    }
    Solution()
    {
        for(int i=2;i<=50000;i++)
        {
            if(isPrime(i))
            arr.push_back(i);
        }
    }
    Node *primeList(Node *head){
        
        Node *p = head;
      
        while(p!=nullptr)
        {
            int x = p->val;
            
            auto y = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
            
            int z = y-1;
            
            
            if(arr[y]==x||z<0)
            {
                p->val = arr[y];
            }
            else
            {
                if(abs(arr[z]-p->val)<=abs(arr[y]-p->val))
                {
                    p->val = arr[z];
                }
                else
                {
                    p->val = arr[y];
                }
            }
            
            p=p->next;
        }
        
        return head;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends