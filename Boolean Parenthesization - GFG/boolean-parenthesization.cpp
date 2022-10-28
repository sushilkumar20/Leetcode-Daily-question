//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    int help(int i, int j,int isTrue, string s, vector<vector<vector<int>>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        
        
        
        if(i==j)
        {
            if(isTrue)
            return s[i]=='T';
            else return s[i]=='F';
        }
        
        if(dp[i][j][isTrue]!=-1)
        return dp[i][j][isTrue];
        
        int cnt=0;
        
        for(int k=i+1;k<j;k+=2)
        {
            int lt = help(i,k-1,1,s,dp);
            int lf = help(i,k-1,0,s,dp);
            int rt = help(k+1,j,1,s,dp);
            int rf = help(k+1,j,0,s,dp);
            
            if(s[k]=='&')
            {
                if(isTrue)
                cnt = (cnt+lt*rt)%mod;
                else
                cnt = (cnt+lt*rf+lf*rt+lf*rf)%mod;
            }
            else if(s[k]=='|')
            {
                if(isTrue)
                cnt = (cnt+lt*rf+lf*rt+lt*rt)%mod;
                else
                cnt = (cnt+lf*rf)%mod;
            }
            else
            {
                if(isTrue)
                cnt = (cnt+lt*rf+lf*rt)%mod;
                else
                cnt = (cnt+lf*rf+lt*rt)%mod;
            }
        }
        
        
        return dp[i][j][isTrue]=cnt;
    }
    int countWays(int N, string S){
        // code here
        
       vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(N+1,vector<int>(2,-1)));
       return help(0,N-1,1,S,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends