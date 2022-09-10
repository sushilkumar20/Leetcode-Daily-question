class Solution {
public:
    
    int help(int i, int k, vector<int>& prices,vector<vector<int>> &dp)
    {
        if(i>=prices.size())
            return 0;
        
        if(k<=0)
            return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        if(k%2==0)
        {
            return dp[i][k] = max(-1*prices[i]+help(i+1,k-1,prices,dp),help(i+1,k,prices,dp));
        }
        else
        {
            return dp[i][k] = max(prices[i]+help(i+1,k-1,prices,dp),help(i+1,k,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int k= 2;
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k+1,-1));
        
        return help(0,2*k,prices,dp);
    }
};