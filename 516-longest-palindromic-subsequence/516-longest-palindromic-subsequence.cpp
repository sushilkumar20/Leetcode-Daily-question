class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
        int n=s.size();
        reverse(s1.begin(),s1.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==s1[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    mx=max(mx,dp[i][j]);
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    mx=max(mx,dp[i][j]);
                }
            }
        }
        
        return mx;
    }
};