class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n =  nums.size();
        long sum=0;
        
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        long t = sum-x;
        
        sum =0;
        
        map<long,int> mp;
        int ans =-1;
        mp[0] = -1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            long rem = sum-t;

            //cout<<t<<" "<<sum<<" "<<rem<<endl;
            if(mp.find(rem)!=mp.end())
            {
                ans = max(ans,i-mp[rem]);
                //break;
            }
            
            if(mp.find(sum)==mp.end())
                mp[sum] = i;
        }
        
        if(sum == x)
        {
            return n;
        }
        if(ans == -1)
            return -1;
        //cout<<ans<<endl;
        return n- ans;
    }
};