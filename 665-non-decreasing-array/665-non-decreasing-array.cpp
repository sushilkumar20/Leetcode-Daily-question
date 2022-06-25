class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n= nums.size();
       vector<int> pref(n);
        vector<int> suff(n);
        
        if(n==1)
            return true;
        
        pref[0]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=nums[i-1])
            {
                pref[i]=(pref[i-1]&1);
            }
            else
                pref[i]=0;
        }
        
        suff[n-1]=1;
        
        for(int i=n-2;i>=0;i--)
        {
             if(nums[i]<=nums[i+1])
            {
                suff[i]=(suff[i+1]&1);
            }
            else
                suff[i]=0;
        }
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(suff[i+1])
                    return true;
            }
            else if(i==n-1)
            {
                if(pref[i-1])
                    return true;
            }
            else 
            {
                if(pref[i-1]&&suff[i+1]&&nums[i-1]<=nums[i+1])
                    return true;
            }
        }
        
        return false;
    }
};