class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i>=grid.size()||i<0||j>=grid[0].size()||j<0||grid[i][j]==0)
            return 0;
        
        //curr++;
        grid[i][j]=0;
       // mx=max(mx,curr);
        
        return 1+dfs(i+1,j,grid)+ dfs(i-1,j,grid)+ dfs(i,j+1,grid)+ dfs(i,j-1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int mx=0;
        
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                   
                   mx=max(mx,dfs(i,j,grid));
                }
            }
        }
        
        return mx;
    }
};