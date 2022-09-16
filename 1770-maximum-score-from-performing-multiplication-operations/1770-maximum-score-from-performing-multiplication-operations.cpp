class Solution {
public:
    int dfs(int i,int k, vector<int>& nums, vector<int>& mult, vector<vector<int>>&dp)
    {
        
        if(k==mult.size())
            return 0;
        if(dp[i][k]!=INT_MIN)
            return dp[i][k];
        
        int left = nums[i]*mult[k]+dfs(i+1,k+1,nums,mult,dp);
        int right = nums[(nums.size()-1)-(k-i)]*mult[k]+dfs(i,k+1,nums,mult,dp);
        
        return dp[i][k]=max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size();
        int m = multipliers.size();
        
        
        vector<vector<int>> dp(m,vector<int>(m,INT_MIN));
        
      
        return dfs(0,0,nums,multipliers,dp);
    }
};