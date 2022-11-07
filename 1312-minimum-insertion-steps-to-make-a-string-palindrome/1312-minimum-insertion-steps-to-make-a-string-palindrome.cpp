class Solution {
public:
    int help(int i, int j,string s, string s1, vector<vector<int>>&dp)
    {
        int n = s.size();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==s1[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }
    int minInsertions(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string s1 = s;
        
        reverse(s1.begin(),s1.end());
        
        int longestPalindromicSubsequence = help(0,0,s,s1,dp);
        // cout<<longestPalindromicSubsequence<<endl;
        return n-longestPalindromicSubsequence;
    }
};