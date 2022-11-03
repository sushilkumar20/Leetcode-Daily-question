class Solution {
public:
    int help(int i, int j,bool&ok, vector<int>&nums1, vector<int>&nums2, vector<vector<int>>&dp)
    {
        if(i==nums1.size()||j==nums2.size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int tak = nums1[i]*nums2[j]+help(i+1,j+1,ok,nums1,nums2,dp);
        int notTak = max(help(i+1,j,ok,nums1,nums2,dp),help(i,j+1,ok,nums1,nums2,dp));
        
        dp[i][j]=max(tak,notTak);
        
        if(dp[i][j]==tak)
            ok=1;
        return dp[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        bool ok = 0;
        
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        int ans = help(0,0,ok,nums1,nums2,dp);
        
        if(ok)
            return ans;
        
       
        ans = INT_MIN;
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                ans=max(ans,nums1[i]*nums2[j]);
            }
        }
        
        return ans;
    }
};