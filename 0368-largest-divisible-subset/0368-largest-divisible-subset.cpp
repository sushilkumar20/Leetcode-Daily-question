class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        vector<int> hash(n);
        vector<int> dp(n);
        
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            hash[i]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    hash[i]=j;
                }
            }
        }
        
        int mx =1;
        
        int ind =0;
        
        for(int i=1;i<n;i++)
        {
            if(dp[i]>mx)
            {
                mx=dp[i];
                ind=i;;
            }
        }
        vector<int> ans;
        while(hash[ind]!=ind)
        {
            ans.push_back(nums[ind]);
            ind = hash[ind];
        }
        
        ans.push_back(nums[ind]);
        
        return ans;
        
    }
};