class Solution {
public:
    void dfs(int i,int j,int cost, vector<vector<int>>& grid,vector<vector<int>>& mat)
    {
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0||grid[i][j]==0||grid[i][j]==-1)
            return;
        if(cost>mat[i][j])
            return ;
        mat[i][j] = min(mat[i][j],cost);
        int p=grid[i][j];
        grid[i][j] = -1;
        dfs(i+1,j,cost+1,grid,mat);
        dfs(i-1,j,cost+1,grid,mat);
        dfs(i,j+1,cost+1,grid,mat);
        dfs(i,j-1,cost+1,grid,mat);
        grid[i][j] = p;
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mat(n,vector<int>(m,INT_MAX));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    dfs(i,j,0,grid,mat);
                }
            }
        }
        
        int mx = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1&&mat[i][j]==INT_MAX)
                    return -1;
                
                if(grid[i][j]!=0)
                mx=max(mat[i][j],mx);
            }
        }
        
        return mx;
    }
};