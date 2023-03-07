class Solution {
public:
    
    bool  pos(vector<int> &tm, long long trp, long long mxTm)
    {
        long long totalTrp = 0;
        
        for(int i=0;i<tm.size();i++)
        {
            if(totalTrp>=trp)
            return 1;
            totalTrp += (mxTm/tm[i]);
        }
        
        if(totalTrp>=trp)
            return 1;
        
        return 0;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long mn = 0;
        long long mx =  1e15;
        
        long long ans = mx;
        
        while(mx>=mn)
        {
            long long mid = (mx+mn)/2;
            
            if(pos(time,totalTrips,mid))
            {
                ans = min(ans,mid);
                mx = mid-1;
            }
            else
            {
                mn=mid+1;
            }
        }
        
        return ans;
    }
};