class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp1(n);
        
        for(int i=0;i<n;i++)
        {
            dp1[i]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }
            }
        }
    
        
        vector<int> dp2(n);
        
        for(int i=0;i<n;i++)
        {
            dp2[i]=1;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[i]>nums[j])
                {
                    dp2[i]=max(dp2[i],1+dp2[j]);
                }
            }
        }
        
       
        int mx =0;
        
        for(int i=0;i<n;i++)
        {
            // cout<<dp1[i]<<" "<<dp2[i]<<endl;
            if(dp1[i]!=1&&dp2[i]!=1)
            mx=max(mx,dp1[i]+dp2[i]-1);
        }
        
        return n-mx;
    }
};