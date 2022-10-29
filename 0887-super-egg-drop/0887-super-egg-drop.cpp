class Solution {
public:
    int cnt;
    int fun(int floor, int egg, vector<vector<int>> &dp)
    {
        if(floor<=1)
            return floor;
      
        if(egg==1)
           return floor;
        if(dp[floor][egg]!=-1)
            return dp[floor][egg];
       
        int mn = INT_MAX;
        
        int l = 1;
        int h = floor;
        
        while(l<=h)
        {
            int mid = (l+h)/2;
            
            int right = fun(floor-mid,egg,dp);
            int left = fun(mid-1,egg-1,dp);
            
            int temp = 1+max(left,right);
            mn = min(temp,mn);
            
            if(right>=left)
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
        return dp[floor][egg] = mn;
    }
    int superEggDrop(int k, int n) {
        
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
       
        int  x= fun(n,k,dp);
       
        return x;
    }
};