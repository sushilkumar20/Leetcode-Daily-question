class Solution {
public:
    int help(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    {
        if(i<0||j<0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i]==word2[j])
            return dp[i][j]=1+help(i-1,j-1,word1,word2,dp);
        
        return dp[i][j]=max(help(i-1,j,word1,word2,dp),help(i,j-1,word1,word2,dp));
    }
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int k=dp[n][m];
        //cout<<k<<endl;
        return n+m-2*k;
    }
};