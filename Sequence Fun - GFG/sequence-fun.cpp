//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    // Code  here
		    int mod = 1e9+7;
		    vector<long long> dp(n+3);
		    dp[1]=2;
		    dp[2]=5;
		    
		    for(long long i=3;i<=n;i++){
		        dp[i]=(dp[i-1]*i+1)%mod;
		    }
		    
		    return dp[n]%mod;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends