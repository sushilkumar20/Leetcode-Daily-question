class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int n = nums.size();
        int mx = 1;
        int curr=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                curr++;
            }
            else
            {
                mx=max(mx,curr);
                curr=1;
            }
        }
        
         mx=max(mx,curr);
        
        return mx;
    }
};