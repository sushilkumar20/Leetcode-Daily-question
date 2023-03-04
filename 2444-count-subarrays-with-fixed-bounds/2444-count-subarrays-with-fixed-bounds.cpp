class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long ans =0;
        
        int n= nums.size();
        
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        int lwMin = -1;
        int lwMax =-0;
        int stA = -1;
        
        for(int i=0;i<n;i++)
        {
            if(mn>=nums[i])
            {
                mn=nums[i];
                lwMin = i;
            }
            
            if(mx<=nums[i])
            {
                 mx=nums[i];
                 lwMax = i;
            }
            
            if(mn == minK &&maxK == mx)
            {
                if(lwMin<=lwMax)
                {
                    ans += (long long)(lwMin-stA);
                }
                else
                    ans += (long long)(lwMax-stA);
            }
            else if(mn<minK||mx>maxK)
            {
                mn = INT_MAX;
                mx = INT_MIN;
                stA = i;
            }
        }
        
        return ans;
        
        
        
    }
};