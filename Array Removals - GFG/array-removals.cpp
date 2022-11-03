//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        
        sort(arr.begin(),arr.end());
        
        int mx=0;
        for(int i=arr.size()-1;i>=0;i--)
        {
            int x = arr[i]-k;
            int ind = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
            
            mx=max(mx,i-ind+1);
            
        }
        
        return arr.size()-mx;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends