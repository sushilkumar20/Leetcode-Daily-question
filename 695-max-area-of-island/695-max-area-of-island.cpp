class Solution {
public:
    void dfs(int i,int j, int&mx, int &curr,vector<vector<int>>& grid)
    {
        if(i>=grid.size()||i<0||j>=grid[0].size()||j<0||grid[i][j]==0)
            return;
        
        curr++;
        grid[i][j]=0;
        mx=max(mx,curr);
        
        dfs(i+1,j,mx,curr,grid);
        dfs(i-1,j,mx,curr,grid);
        dfs(i,j+1,mx,curr,grid);
        dfs(i,j-1,mx,curr,grid);
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
                    int curr=0;
                    dfs(i,j,mx,curr,grid);
                }
            }
        }
        
        return mx;
    }
};