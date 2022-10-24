class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]&&dp[i]<dp[j]+1)
                {
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(nums[i]>nums[j]&&dp[i]==dp[j]+1)
                    cnt[i]+=cnt[j];
            }
        }
        
        int mx =0;
        
        for(int i=0;i<n;i++)
            mx=max(mx,dp[i]);
        
        int ans= 0; 
        for(int i=0;i<n;i++)
        {
            if(mx==dp[i])
                ans+=cnt[i];
        }
        
        return ans;
    }
};