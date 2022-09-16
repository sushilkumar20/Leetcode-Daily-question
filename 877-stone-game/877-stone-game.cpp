class Solution {
public:
    int dfs(int i,int t,vector<int>& piles,vector<vector<int>> &dp)
    {
        if(i>=piles.size())
            return 0;
        
        if(dp[i][t]!=-1)
            return dp[i][t];
        int k = piles[i]+dfs(i+1,(t+1)%2,piles,dp);
        
        int x = piles.back();
        piles.pop_back();
        
        int k1 = x+dfs(i,(t+1)%2,piles,dp);
        piles.push_back(x);
        return dp[i][t] = max(k,k1);
    }
    bool stoneGame(vector<int>& piles) {
        
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        dfs(0,0,piles,dp);
        
        if(dp[0][0]>dp[0][1])
            return true;
        
        return false;
    }
};