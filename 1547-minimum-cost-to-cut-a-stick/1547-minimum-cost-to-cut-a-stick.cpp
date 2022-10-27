class Solution {
public:
    int help(int i, int j, vector<int>&cuts, vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;
        
        int min_cost = INT_MAX;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        for(int k=i;k<=j;k++)
        {
            int cost = cuts[j+1]-cuts[i-1]+help(i,k-1,cuts,dp)+help(k+1,j,cuts,dp);
            min_cost = min(min_cost,cost);
        }
        
        return dp[i][j]=min_cost;
    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        return help(1,cuts.size()-2,cuts,dp);
    }
};