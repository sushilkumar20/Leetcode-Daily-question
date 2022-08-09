class Solution {
public:
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9+7;
        int n= arr.size();
        sort(arr.begin(),arr.end());
        vector<long long> dp(n);
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[arr[i]] = i;
        
        for(int i=0;i<n;i++)
        {
            int cnt =1;
            for(int j=0;j<n;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    int right = arr[i]/arr[j];
                    
                    if(mp.find(right)!=mp.end())
                    {
                        cnt=(cnt%mod+(dp[j]*dp[mp[right]])%mod)%mod;
                    }
                }
                
            }
            
            dp[i] = cnt%mod;
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
            ans=(ans+dp[i])%mod;
        
        return ans;
    }
};