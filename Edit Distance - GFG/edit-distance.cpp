//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int help(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        
        
        if(i==s.size())
        return t.size()-j;
        
        if(j==t.size())
        return  s.size()-i;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(s[i]==t[j])
        return dp[i][j] = help(i+1,j+1,s,t,dp);
        
        int rm = 1+help(i+1,j,s,t,dp);
        int rp = 1+ help(i+1,j+1,s,t,dp);
        int is = 1+ help(i,j+1,s,t,dp);
        
        return dp[i][j] = min({rm,rp,is});
    }
    int editDistance(string s, string t) {
        // Code here
        int n = s.size();
        int m = t.size();
         
         vector<vector<int>> dp(n, vector<int>(m,-1));
         
         return help(0,0,s,t,dp);
         
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends