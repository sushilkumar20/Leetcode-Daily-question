class Solution {
public:
    bool ok(int mid, vector<int> &nums,int k)
    {
        int n=nums.size();
        
        int sum=0;
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mid)
                return false;
            
            if(sum+nums[i]<=mid)
            {
                sum+=nums[i];
            }
            else
            {
                cnt++;
                sum=nums[i];
            }
        }
        
        cnt++;
        
        if(cnt<=k)
            return true;
        
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0;
        int r=(int)1e9+1;
        
        while(l<r)
        {
            int mid= (r+l)/2;
            
            if(ok(mid,nums,m))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return l;
    }
};