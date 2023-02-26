class Solution {
public:
    
    bool pos(int sm, int k, vector<int> &nums)
    {
        int cnt=1;
        int curr=0;
        
        for(int i=0;i<nums.size();i++)
        {   
            if(nums[i]>sm)
                return 0;
            if(curr+nums[i]>sm)
            {
                cnt++;
                curr=nums[i];
            }
            else
                curr+=nums[i];
        }
        
        if(cnt>k)
            return 0;
        
        return 1;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int lw = 0;
        int hg = 1e9;
        
        int ans = hg;
        while(lw<=hg)
        {
            int mid = (lw+hg)/2;
            
            if(pos(mid,k,nums))
            {
                ans=min(ans,mid);
                hg=mid-1;
            }
            else
            {
                lw = mid+1;
            }
        }
        
        return ans;
    }
};