//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int help(int i, int sum, int N,  int k,vector<vector<vector<int>>> &dp)
  {
      if(sum==N){
          if(k==0)
          return 1;
      
          return 0;
      }
      
      if(sum>N)
      return 0;
      
      if(k==0)
      return 0;
      
      if(i>N)
      return 0;
      
      if(dp[i][sum][k]!=-1)
      return dp[i][sum][k];
      
      return dp[i][sum][k] = help(i,sum+i,N,k-1,dp) +  help(i+1,sum,N,k,dp);
  }
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(K+1,-1)));
        
   
        return help(1,0,N,K,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends