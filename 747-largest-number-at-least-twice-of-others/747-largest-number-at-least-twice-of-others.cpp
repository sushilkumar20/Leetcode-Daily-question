class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int j=0;
        int mx=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(mx<nums[i])
            {
                mx=nums[i];
                j=i;
            }
        }
      
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[j])
                continue;
            if(nums[i]*2>nums[j])
                return -1;
        }
        
        return j;
    }
};