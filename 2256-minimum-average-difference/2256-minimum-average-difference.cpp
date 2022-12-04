class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int ind = -1;
        
        long long mx = 1e18;
        
        int n = nums.size();
        vector<long long > pref(n);
        vector<long long> suff(n);
        
        pref[0] = nums[0];
        
        for(int i=1;i<n;i++)
        {
            pref[i] = nums[i]+pref[i-1];
        }
        
        suff[n-1] = nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            suff[i] = nums[i]+suff[i+1];
        }
        
        for(int i=0;i<n;i++)
        {
            long long  z = pref[i]/(i+1);
            long long q = 0;
            if(i+1<n)
            q=suff[i+1]/(n-i-1);
            
            if(abs(z-q)<mx)
            {
                mx=abs(z-q);
                ind=i;
            }
        }
        
        return ind;
    }
};