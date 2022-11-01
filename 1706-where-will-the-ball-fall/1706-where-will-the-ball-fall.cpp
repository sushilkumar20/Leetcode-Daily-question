class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>&grid)
    {
        if(i==grid.size())
            return j;
        
        int nxtClm = j+grid[i][j];
        if(nxtClm<0||nxtClm>=grid[0].size()||grid[i][j]!=grid[i][nxtClm])
            return -1;
        
        return dfs(i+1,nxtClm,grid);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid[0].size();
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            ans[i]= dfs(0,i,grid);
            // cout<<"ii"<<endl;
        }
        
        return ans;
    }
};