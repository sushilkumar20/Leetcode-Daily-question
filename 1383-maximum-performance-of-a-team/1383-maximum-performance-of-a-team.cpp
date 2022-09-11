class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        int mod = 1e9+7;
        vector<pair<long long,long long>> vp;
        
        for(int i=0;i<n;i++)
        {
            vp.push_back({efficiency[i],speed[i]});
        }
        
        sort(vp.rbegin(),vp.rend());
        
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
         long long cnt = 0;
        long long ans = 0;
        long long sum = 0;
       
        for(int i=0;i<n;i++)
        {
            pq.push(vp[i].second);
            sum+=vp[i].second;
           
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            
            
            ans=max(ans,sum*vp[i].first);
        }
        
        return ans%mod;
    }
};