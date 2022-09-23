class Solution {
public:
    int concatenatedBinary(int n) {
        
        int mod = 1e9+7;
        
        long long ans = 0;
        for(int i=1;i<=n;i++)
        {
            int nb = (log(i))/log(2)+1;
            
            ans= ((ans<<nb)%mod+i)%mod;
        }
        
        
        
        return ans%mod;
    }
};