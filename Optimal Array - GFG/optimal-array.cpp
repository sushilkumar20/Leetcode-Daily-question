//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        
        
        int sum =0;
        
       vector<int> ans;
       
       vector<int> prf(n);
       
       for(int i=0;i<n;i++)
       {
           if(i==0)
           {
               prf[i]=a[i];
           }
           else
           {
               prf[i] = prf[i-1]+a[i];
           }
       }
       
       for(int i=0;i<n;i++)
       {
           int x = (i+1)/2;
           
           int y = x-1;
           
           int ans1= 0;
           
           if(y>=0)
           {
               int z = a[x] * (y+1);
               ans1  += abs(z - prf[y]);
           }
           
        //   cout<<ans1<<" "<<x<<endl;
           int z = a[x] * (i-x);
           ans1  += abs(z - (prf[i]-prf[x]));
           
           ans.push_back(ans1);
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends