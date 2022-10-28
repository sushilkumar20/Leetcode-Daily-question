class Solution {
public:
    int help(int i, int k, vector<int> &arr, vector<int> &dp)
    {
        if(i==arr.size())
        {
            return 0;
        }
        
        if(dp[i]!=-1)
            return dp[i];
        
        int mx = 0;
        
        int mxTillNow = 0;
        
        for(int j=i;j<min(i+k,(int)arr.size());j++)
        {
            mxTillNow = max(mxTillNow,arr[j]);
            
            int sum1 = mxTillNow*(j-i+1);
            // if(i==0){
            // cout<<sum1<<endl;
            // }
            mx=max(sum1+help(j+1,k,arr,dp),mx);
            
        }
        
        return dp[i]=mx;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        vector<int> dp(arr.size(),-1);
        return help(0,k,arr,dp);
    }
};