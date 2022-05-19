class Solution {
public:
    int dfs(int i,int j,int &n,int &m, vector<vector<int>> &dp)
    {
        if(i>=n||j>=m)
            return 0;
        if(i==n-1&&j==m-1)
        {
           return 1;
        }
        if(dp[j][i]!=-1)
            return dp[j][i];
        int x=dfs(i+1,j,n,m,dp);
        int y=dfs(i,j+1,n,m,dp);
        
        dp[j][i]=x+y;
        
        return dp[j][i];
    }
    int uniquePaths(int m, int n) {
        
        int cnt=0;
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
       
        
        return  dfs(0,0,n,m,dp);
    }
};