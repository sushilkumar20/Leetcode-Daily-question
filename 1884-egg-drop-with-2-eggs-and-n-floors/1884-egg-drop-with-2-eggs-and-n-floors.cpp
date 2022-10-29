class Solution {
public:
    int help(int floor, int egg, vector<vector<int>>&dp)
    {
        if(floor<=1)
            return floor;
        
        if(egg==1)
            return floor;
        
        if(dp[floor][egg]!=-1)
            return dp[floor][egg];
        
        int mn = INT_MAX;
        
        for(int k=1;k<floor;k++)
        {
            int temp = 1+max(help(k-1,egg-1,dp),help(floor-k,egg,dp));
            mn= min(mn,temp);
        }
        
        return dp[floor][egg]=mn;
    }
    int twoEggDrop(int n) {
        
        
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        
        return help(n,2,dp);
    }
};