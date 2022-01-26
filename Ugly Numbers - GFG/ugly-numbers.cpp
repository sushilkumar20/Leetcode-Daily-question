// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    
	    int c2=0;
	    int c3=0;
	    int c5=0;
	    
	    vector<ull> dp(n);
	    
	    dp[0]=1;
	    
	    for(int i=1;i<n;i++)
	    {
	        dp[i]=min({dp[c2]*2,dp[c3]*3,dp[c5]*5});
	        
	        if(dp[i]==dp[c2]*2)
	        c2++;
	         if(dp[i]==dp[c3]*3)
	        c3++;
	         if(dp[i]==dp[c5]*5)
	        c5++;
	        
	        //cout<<dp[i]<<endl;
	    }
	    
	    return dp[n-1];
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends