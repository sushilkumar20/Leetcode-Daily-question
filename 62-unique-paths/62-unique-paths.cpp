class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>&dp)
    {
        if(i<0||j<0||i>=m||j>=n)
            return 0;
        
        if(i==0||j==0)
        {
            if(dp[i][j]==-1)
                dp[i][j]=1;
            else
                dp[i][j]++;
            return dp[i][j];
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = dfs(i-1,j,m,n,dp)+dfs(i,j-1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        dfs(m-1,n-1,m,n,dp);
        
        return dp[m-1][n-1];
    }
};