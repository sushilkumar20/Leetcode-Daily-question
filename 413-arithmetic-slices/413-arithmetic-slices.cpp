class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        
        if(nums.size()<=2)
            return 0;
        
        int count =0;
        int ans=0;
        
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]-nums[i+1]==nums[i+1]-nums[i+2])
            {
                count++;
                ans+=count;
            }
            else
            {
                count=0;
            }
        }
        
        return ans;
    }
};