//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        string ans ="";
        int mx=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
            
            if(mx<1)
            {
                mx=dp[i][i];
                ans=s.substr(i,mx);
            }
        }
        
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = 1;
                
                if(mx<2)
                {
                    mx=2;
                    ans=s.substr(i,2);
                }
            }
        }
        
        
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                int j=i+k-1;
                
                if(s[i]==s[j]&&dp[i+1][j-1])
                {
                    dp[i][j]=1;
                    if(mx<k)
                    {
                        mx=k;
                        ans=s.substr(i,k);
                    }
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends