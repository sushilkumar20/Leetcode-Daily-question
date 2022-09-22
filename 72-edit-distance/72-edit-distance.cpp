class Solution {
public:
    
    int help(int i, int j, string s1, string s2, vector<vector<int>> &dp)
    {
        if(i<0&&j<0)
            return 0;
        if(j<0)
            return i+1;
        
         if(i<0)
             return j+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = help(i-1,j-1,s1,s2,dp);
        else
        {
            // delete replace insert
            return dp[i][j]=min({1+help(i-1,j,s1,s2,dp),1+help(i-1,j-1,s1,s2,dp),1+help(i,j-1,s1,s2,dp)});
        }
    }
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        
          for(int i=0;i<=m;i++)
        {
            dp[0][i]=i;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                    dp[i][j] = 1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                
                // insert delete replace
            }
        }
        
        return dp[n][m];
    }
};