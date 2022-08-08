class Solution {
public:
    int help(int i, int j, vector<int>&nums, vector<vector<int>> &dp)
    {
        if(i==nums.size())
            return 0;
        if(dp[i][j+1]!=-1)
            return dp[i][j+1];
        
        if(j==-1)
        {
            return dp[i][j+1] = max(help(i+1,j,nums,dp),1+help(i+1,i,nums,dp));
        }
        
        if(nums[i]>nums[j])
            return dp[i][j+1] = max(help(i+1,j,nums,dp),1+help(i+1,i,nums,dp));
        
        return dp[i][j+1] = help(i+1,j,nums,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int mx=0;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        
       return help(0,-1,nums,dp);
    }
};