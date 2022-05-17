class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int mx = nums[0];
        
        for(int i=0;i<nums.size();i++)
        {
            mx=max(mx,nums[i]);
        }
        
        if(mx<0)
            return mx;
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mx=max(mx,sum);
            if(sum<0)
                sum=0;
            
        }
        
        return mx;
    }
};