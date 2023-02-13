//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
     
     int help(int i, int prv, vector<vector<int>> &col,vector<vector<int>> &dp)
     {
         if(i==col.size())
         return 0;
         if(dp[i][prv+1]!=-1)
         return dp[i][prv+1];
         
         if(prv==-1)
         {
             return dp[i][prv+1]=min({col[i][0]+help(i+1,0,col,dp),col[i][1]+help(i+1,1,col,dp),col[i][2]+help(i+1,2,col,dp)});
         }
         else if(prv == 0)
         {
              return dp[i][prv+1]=min({col[i][1]+help(i+1,1,col,dp),col[i][2]+help(i+1,2,col,dp)});
         }
         else if(prv == 1)
         {
             return dp[i][prv+1]= min({col[i][0]+help(i+1,0,col,dp),col[i][2]+help(i+1,2,col,dp)});
         }
         else
         {
             return dp[i][prv+1]=min({col[i][0]+help(i+1,0,col,dp),col[i][1]+help(i+1,1,col,dp)});
         }
     }
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>> dp(N,vector<int>(4,-1));
        
        return help(0,-1,colors,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends