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
        
        if(n<=2)
            return 1;
        
        if(n==3)
            return 2;
        
        int prod = 1;
        
        while(n>4)
        {
            prod*=3;
            n-=3;
        }
        prod*=n;
        return prod;
    }
};