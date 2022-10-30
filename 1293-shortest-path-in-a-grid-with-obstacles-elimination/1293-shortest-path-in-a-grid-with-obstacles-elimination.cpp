class Solution {
public:
    int help(int i, int j,int k, vector<vector<int>>&grid,vector<vector<vector<int>>> &dp,vector<vector<bool>>&vis)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j])
            return 1e9;
        
       
        
        
         if(grid[i][j]==1)
         {
             if(k==0)
                 return dp[i][j][k] = 1e9;
             else
                 k--;
         }
        
         if(i==0&&j==0)
            return dp[i][j][k] = 0;
        
         if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        
        
         vis[i][j]=1;
        
         dp[i][j][k]= 1+min({help(i+1,j,k,grid,dp,vis),
                                    help(i,j+1,k,grid,dp,vis),
                                    help(i-1,j,k,grid,dp,vis),
                                    help(i,j-1,k,grid,dp,vis)});
        vis[i][j]=false;
        
        return dp[i][j][k];
         
    
    // return 0;
    }
    int shortestPath(vector<vector<int>>&grid, int k) {
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        vector<vector<bool>> visited(n+1,vector<bool>(m+1,false));
        // int x = help(n-1,m-1,k,grid,dp,visited);
        
         int x = path( grid,  k,  n-1,  m-1, visited, dp);
        
        if(x>n*m)
            return -1;
        return x;
    }
    
    int path(vector<vector<int>>& grid, int k, int r, int c,vector<vector<bool>>& visited, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(r >= m || c >= n || r < 0 || c < 0 || visited[r][c]){
            return 1e6;
        }

        if(dp[r][c][k] != -1){
            return dp[r][c][k];
        }
        
        if(r == 0 && c == 0){
            return dp[r][c][k] = 0;
        }

        if(grid[r][c]){
            if(k == 0){
                return dp[r][c][k] = 1e6;
            }
            else{
                k--;
            }
        }
        
        visited[r][c] = true;
        int top = 1+path(grid, k, r-1, c,visited, dp);
        int left = 1+path(grid, k, r, c-1,visited, dp);
        int down = 1+path(grid, k, r+1, c,visited, dp);
        int right = 1+path(grid, k, r, c+1,visited, dp);
        visited[r][c] = false;

        return dp[r][c][k] = min(top, min(left, min(right, down)));
    }
};