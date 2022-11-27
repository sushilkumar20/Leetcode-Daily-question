class Solution {
public:
    int help(int i, int prev, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(i==nums.size())
            return 0;
        
        if(prev==-1)
            return help(i+1,i,nums,dp)+help(i+1,prev,nums,dp);
        
        int cnt = 0;
        
        // cnt += help(i+1,prev,nums,dp);
        
        for(int k=i+1;k<nums.size();k++)
        {
            if(nums[i]-nums[prev]==nums[k]-nums[i]){
                cnt+=(1+help(k,i,nums,dp)+help(k,prev,nums,dp));
            }
            else
                cnt+=help(k,prev,nums,dp);
        }
        
        return cnt;
        
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        long long ans = 0;
        
        vector<map<long long,int>> cnt(n);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long diff = (long long)nums[i]-nums[j];
                
                long long sum = 0;
                
                if(cnt[j].find(diff)!=cnt[j].end())
                {
                    sum = cnt[j][diff];
                }
                
                cnt[i][diff] += (sum+1);
                ans+=sum;
            }
        }
        
        return ans;
        
        
        
    }
};