//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool pos(int mid, int arr[], int n, int k)
    {
        int curr=1;
        int s=0;
        
        for(int i=0;i<n;i++)
        {
            if(s+arr[i]>mid)
            {
                curr++;
                s=0;
            }
            s+=arr[i];
            
            
        }
        
        
        if(curr<=k&&s<=mid)
        return 1;
        
        return 0;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        
        int sum = 0;
        
        for(int i=0;i<N;i++)
        sum+=arr[i];
        
         int lw = 0;
        
         for(int i=0;i<N;i++)
         lw=max(lw,arr[i]);
        
        int hg = sum;
        
        int ans = hg;
        
        while(lw<=hg)
        {
            int mid = lw+(hg-lw)/2;
            
            if(pos(mid,arr,N,K))
            {
               
                ans = min(ans,mid);
                hg=mid-1;
            }
            else
            {
                lw=mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends