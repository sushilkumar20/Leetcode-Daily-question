class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        
        int mod = 1e9+7;
        
        int n = nums.size();
        
        vector<long long> pref(n);
        
        pref[0] = nums[0];
        
        for(int i=1;i<n;i++)
            pref[i] = pref[i-1]+nums[i];
        
        long long ans = 0; 
        for(int i=0;i<n-2;i++)
        {
            long long sum = pref[i];
            
            long long srh = 2*sum;
            
            auto k = lower_bound(pref.begin()+i+1,pref.end(),srh)-pref.begin();
            
            if(k>=n-1)
                break;
           // cout<<k<<endl;
            if(pref[k]-pref[i]>pref[n-1]-pref[k])
                continue;
            
           
            int l = k;
            int h = n-2;
            int ld = k;
            while(l<=h)
            {
                int mid = (l+h)/2;
                
                if(pref[mid]-pref[i]<=pref[n-1]-pref[mid])
                {
                    ld = mid;
                    l=mid+1;
                }
                else
                {
                    h=mid-1;
                }
            }
            
            //cout<<k<<" "<<ld<<endl;
            ans = (ans+(ld-k+1))%mod;
            
        }
        
        return ans;
        
    }
};