class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        if(n==1)
            return 0;
        vector<int> pref(n);
        vector<int> suff(n);
        
        pref[0] = height[0];
        
        for(int i=1;i<n;i++)
            pref[i] = max(height[i],pref[i-1]);
        
        suff[n-1] = height[n-1];
        
        for(int i=n-2;i>=0;i--)
            suff[i] = max(height[i],suff[i+1]);
        
        int ans = 0;
        
        for(int i=1;i<n-1;i++)
        {
            if(height[i]<min(pref[i-1],suff[i+1]))
           ans+=min(pref[i-1],suff[i+1])-height[i];
        }
        
        return ans;
    }
};