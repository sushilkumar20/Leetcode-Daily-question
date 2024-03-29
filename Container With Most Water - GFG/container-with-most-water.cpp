//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long arr[], int n)
{
    // Your code goes here
   long long mx =0;
   long long i =0;
   long long j = n-1;
   
   while(i<j)
   {
       if(arr[i]<arr[j])
       {
           mx=max(mx,arr[i]*(j-i));
           i++;
       }
       else
       {
            mx=max(mx,arr[j]*(j-i));
            j--;
       }
   }
   
   return mx;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends