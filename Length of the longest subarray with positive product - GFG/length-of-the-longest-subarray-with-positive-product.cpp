//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int mx = 0;
           
           int j=0;
           int j1=-1;
           int cnt=0;
           
           for(int i=0;i<n;i++)
           {
               if(arr[i]==0)
               {
                   j=i+1;
                   j1=-1;
                   cnt=0;
                   continue;
               }
               if(arr[i]<0)
               {
                   cnt++;
               }
               if(cnt%2)
               {
                   if(j1==-1)
                   j1=i;
               }
               
               if(cnt%2==0)
               {
                   mx=max(mx,i-j+1);
                //   cout<<i<<" "<<j<<endl;
               }
               else if(j!=-1)
               {
                   mx=max(mx,j1-j);
                   mx=max(mx,i-j1);
               }
              
               
           }
           
           return mx;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends