class Solution {
public:
    int help(int i, int j, vector<int>&nums1, vector<int>&nums2, vector<vector<int>>&dp)
    {
        if(i<0||j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(nums1[i]==nums2[j])
        {
            return dp[i][j] = 1+help(i-1,j-1,nums1,nums2,dp);
        }
        else{
             dp[i][j] = 0;
            help(i-1,j,nums1,nums2,dp);
            help(i,j-1,nums1,nums2,dp);
           
            return 0;
        }
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                    mx=max(mx,dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
        }
        
        return mx;
    }
};