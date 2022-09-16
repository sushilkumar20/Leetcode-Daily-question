class Solution {
public:
    
    int dfs(int i, int j, int t, vector<int>& piles,  vector<vector<vector<int>>> &dp)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j][t]!=-1)
            return dp[i][j][t];
        
        if(t==0)
        {
            int left = piles[i]+dfs(i+1,j,1,piles,dp);
            int right = piles[j]+dfs(i,j-1,1,piles,dp);
            
            return dp[i][j][0] = max(left,right);
        }
        else
        {
            int left = dfs(i+1,j,0,piles,dp);
            int right = dfs(i,j-1,0,piles,dp);
            
            return dp[i][j][0] = min(left,right);
        }
    }
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        
        int pa = dfs(0,n-1,0,piles,dp);
        
        int tot =0;
        
        for(int i=0;i<n;i++)
            tot+=piles[i];
        
        int pb = tot-pa;
        
        if(pa>pb)
            return 1;
        return 0;
    }
};