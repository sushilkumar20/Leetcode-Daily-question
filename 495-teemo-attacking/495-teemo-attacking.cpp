class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        
        int ans=0;
        
        int size=t.size();
        for(int i=0;i<size-1;i++)
        {
            ans+=min(t[i+1]-t[i],d);
        }
        
        ans+=d;
        
        return ans;
    }
};