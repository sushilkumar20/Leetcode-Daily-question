class Solution {
public:
    int help(int i, int j, vector<int>&piles,  vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=max(piles[i]-help(i+1,j,piles,dp),piles[j]-help(i,j-1,piles,dp));
        
    }
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return help(0,n-1,piles,dp)>0;
    }
};