class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mx=nums[0];
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            mx=max(mx,sum);
            
            if(sum<0)
                sum=0;
        }
        
        if(mx<0)
            return mx;
        
        
        int sum1=0;
        int mn=INT_MAX;
        int k=0;
        
        for(int i=0;i<n;i++)
        {
            k+=nums[i];
            sum1+=nums[i];
            mn=min(mn,sum1);
            
            if(sum1>0)
                sum1=0;
        }
        
        return max(k-mn,mx);
        
    }
};