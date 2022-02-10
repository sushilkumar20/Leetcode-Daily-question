class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        vector<int> pref(n);
        
        pref[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
        }
        
        int ans=INT_MAX;
        
        int sum=0;
        for(int i=n;i>=0;i--)
        {
            if(i!=n)
            {
                sum+=nums[i];
                 if(sum==x)
                {
                    ans=min(ans,n-i);
                }
            }
               
                
                int k=lower_bound(pref.begin(),pref.end(),x-sum)-pref.begin();
                if(k>=pref.size()||k>=i)
                    continue;
                //cout<<k<<endl;
                if(pref[k]!=x-sum)
                    continue;
               // cout<<k<<endl;
               
            
               ans=min(ans,k+1+n-i);
            
        }
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
};