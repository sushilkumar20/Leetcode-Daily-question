class Solution {
public:
    
    int help(int i, int k, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(nums.size()-i<k)
            return 1e9;
        
        if(k==1)
        {
            int sum=0;
            
            for(int j=i;j<nums.size();j++)
                sum+=nums[j];
            
            return sum;
        }
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int curr=0;
        
        int mx = 1e9;
        for(int j=i;j<nums.size();j++)
        {
            curr+=nums[j];
            
            mx = min(mx,max(curr,help(j+1,k-1,nums,dp)));
        }
        
        return dp[i][k]=mx;
    }
    int splitArray(vector<int>& nums, int k) {
        
        
        vector<vector<int>> dp(nums.size(),vector<int>(k+1,-1));
        return help(0,k,nums,dp);
    }
};