class Solution {
public:
    
    int help(int tar, int i, vector<int>&arr,vector<vector<int>> &dp)
    {
        if(i<0)
            return 1e9;
        
        if(tar==0)
            return 0;
        
        if(tar<0)
            return 1e9;
        
        if(dp[tar][i]!=-1)
            return dp[tar][i];
        
        int take = 1e9;
        if(arr[i]<=tar)
        {
            take = 1+help(tar-arr[i],i,arr,dp);
        }
        int nTake = help(tar,i-1,arr,dp);
        
        return dp[tar][i] = min(take,nTake);
    }
    int numSquares(int n) {
        
        vector<int> arr;
        
        for(int i=1;i*i<=n;i++)
            arr.push_back(i*i);
        
        sort(arr.rbegin(),arr.rend());
        
        vector<vector<int>> dp(n+1,vector<int>(arr.size(),-1));
        
        return  help(n,arr.size()-1,arr,dp);
        
        
        
    }
};