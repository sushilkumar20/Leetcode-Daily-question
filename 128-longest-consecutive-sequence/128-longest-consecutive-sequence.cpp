class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()<=0)
            return 0;
        sort(nums.begin(),nums.end());
        
        int curr = 1;
        int mx = 1;
        int n = nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]<=1)
            {
                if(nums[i]-nums[i-1]==1)
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