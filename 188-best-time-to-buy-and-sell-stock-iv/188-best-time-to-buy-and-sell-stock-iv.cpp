class Solution {
public:
    int help(int i, int k ,vector<int>& prices, vector<vector<int>> &dp)
    {
        if(i>=prices.size())
            return 0;
        
        if(k<=0)
            return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        if(k%2==0)
        {
            // if(i==prices.size()-1)
            //     return 0;
            
            // buying
            return dp[i][k]= max(-1*prices[i]+help(i+1,k-1,prices,dp),help(i+1,k,prices,dp));;
        }
        else
        {
            // sell
            int x = max(prices[i]+help(i+1,k-1,prices,dp),help(i+1,k,prices,dp));
            return dp[i][k]=x;
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        
        int cnt = 0;
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k+1,-1));
        
        return help(0,2*k,prices,dp);
    }
};