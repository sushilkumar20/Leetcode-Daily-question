class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        long long sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            nums[i]=nums[i]%p;
            // cout<<nums[i]<<endl;
        }
        
        long long rem = sum%p;
        // cout<<rem<<endl;
        if(rem == 0)
            return 0;
        
        map<int,int> mp;
        sum=0;
        int mx = INT_MAX;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            sum=sum%p;
            long long to_find = (sum-rem+p)%p;
            if(mp.find(to_find)!=mp.end())
            {
                mx=min(mx,i-mp[to_find]);
            }
            mp[sum] = i;
        }
        
        // cout<<mx<<endl;
        if(mx>=nums.size())
            return -1;
        return mx;
    }
};