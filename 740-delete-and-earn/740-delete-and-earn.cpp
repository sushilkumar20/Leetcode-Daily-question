class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        map<int,int> mp;
        
        int mx=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            mx=max(mx,nums[i]);
        }
        
        vector<int> dp(mx+3);
        
        
        dp[0]=0;
        dp[1]=mp[1];
        dp[2]=max(mp[1],2*mp[2]);
        
        for(int i=3;i<=mx;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+i*mp[i]);
        }
        
        return dp[mx];
    }
};