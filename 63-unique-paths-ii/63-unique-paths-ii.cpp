class Solution {
public:
    int help(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())
            return 0;
         if(grid[i][j]==1)
            return dp[i][j]=0;
        if(i==grid.size()-1&&j==grid[0].size()-1)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
      
        
        
        
        return dp[i][j]= help( i+1, j, grid,dp)+ help( i, j+1, grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                dp[i][j]=-1;
        }
        
       return help(0,0,grid,dp);
        
    }
};