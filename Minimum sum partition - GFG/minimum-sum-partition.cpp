//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int sum =0;
	    
	    for(int i=0;i<n;i++)
	    sum+=arr[i];
	    
	    vector<vector<int>> dp(n+1,vector<int>(sum+1));
	    
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0]=1;
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(j>=arr[i-1])
	            {
	                dp[i][j]=dp[i-1][j]|dp[i-1][j-arr[i-1]];
	            }
	            else
	            dp[i][j]=dp[i-1][j];
	        }
	    }
	    
	   // for(int i=0;i<=n;i++)
	   // {
	   //     for(int j=0;j<=sum;j++)
	   //     {
	   //         cout<<dp[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    int mx = sum;
	    for(int i=0;i<=sum;i++)
	    {
	        int x = mx;
	        if(dp[n][i])
	        mx=min(mx,abs(i-(sum-i)));
	        
	       // if(x!=mx)
	       // cout<<i<<endl;
	    }
	    
	    return mx;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends