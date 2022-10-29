class Solution {
public:
    bool pos(long long mid, int m, int k, vector<int>&arr)
    {
        int cnt = 0;
        
        int curr = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=mid)
            {
                curr++;
                if(curr>=k)
                {
                    cnt++;
                    curr=0;
                }
            }
            else
            {
                curr=0;
            }
        }
         // cout<<cnt<<" "<<mid<<endl;
        return cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        
        long long lw = 1;
        long long hg = 0;
        
        
        for(int i=0;i<n;i++)
        {
            hg+=bloomDay[i];
        }
        
        if(n<(long long)m*(long long)k)
            return -1;
        
        long long mx = hg;
        while(lw<=hg)
        {
            long long mid = (lw+(hg-lw)/2);
            
            if(pos(mid,m,k,bloomDay))
            {
                
             
                mx=min(mx,mid);
                hg=mid-1;
            }
            else
                lw=mid+1;
        }
        
        return mx;
        
    }
};