class Solution {
public:
    
    bool pos(int speed, vector<int> &piles, int h)
    {
        long long tot = 0;
        
        for(int i=0;i<piles.size();i++)
        {
            tot += piles[i]/speed;
            
            if(piles[i]%speed)
                tot++;
        }
        
        if(tot<=h)
            return 1;
        
        return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int lw = 1;
        int hg = 1;
        
        for(auto i:piles)
            hg = max(hg,i);
        
        int ans = hg;
        while(lw<=hg)
        {
            int mid = (hg+lw)/2;
            
            if(pos(mid,piles,h))
            {
                ans = min(ans,mid);
                hg =  mid-1;
            }
            else
            {
                lw = mid+1;
            }
        }
        
        return ans;
    }
};