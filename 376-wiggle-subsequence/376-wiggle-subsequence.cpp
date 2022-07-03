class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int up =1;
        int dow =1;
        
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                dow=up+1;
            }
            else if(nums[i]<nums[i-1])
            {
                up= dow+1;
            }
        }
        
        return max(up,dow);
    }
};