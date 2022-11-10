class Solution {
public:
    int help(int i,int sum,vector<int>&arr, vector<vector<int>> &dp)
    {
        if(sum==0)
            return 1;
        if(sum<0)
            return 0;
        
        if(i==arr.size())
            return 0;
        
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        
        int notTake = help(i+1,sum,arr,dp);
        int take = 0;
        if(arr[i]<=sum)
        {
             take = arr[i]*help(i,sum-arr[i],arr,dp);
        }
        
        return dp[i][sum] = max(take,notTake);
    }
    int integerBreak(int n) {
        
        vector<int> arr;
        
        
        for(int i=1;i<n;i++)
        {
            arr.push_back(i);
        }
        
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return help(0,n,arr,dp);
        
    }
};