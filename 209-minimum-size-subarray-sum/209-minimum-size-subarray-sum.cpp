class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int ans=INT_MAX;
        int left=0;
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            
            while(left<nums.size() && sum>=target)
            {
                ans=min(ans,i-left+1);
                sum-=nums[left];
                left++;
            }
        }
        
        if(ans==INT_MAX)return 0;
        
        return ans;
    }
};