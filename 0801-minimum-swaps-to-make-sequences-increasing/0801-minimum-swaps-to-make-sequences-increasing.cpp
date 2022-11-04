class Solution {
public:
    int help(int i,int prv, vector<int>&arr1, vector<int> &arr2, vector<vector<int>>&dp)
    {
        // cout<<i<<endl;
        if(i==arr1.size())
        {
            return 0;
        }
        
        if(dp[i][prv]!=-1)
            return dp[i][prv];
        
        if(i==0)
        {
            return dp[i][prv]=min(help(i+1,0,arr1,arr2,dp),1+help(i+1,1,arr1,arr2,dp));
        }
        else
        {
            if(prv==0)
            {
                if(arr1[i]>arr1[i-1]&&arr2[i]>arr2[i-1])
                {
                    int noChange = help(i+1,0,arr1,arr2,dp);
                    int change = 1e9;
                    
                    if(arr2[i]>arr1[i-1]&&arr1[i]>arr2[i-1])
                        change = 1+help(i+1,1,arr1,arr2,dp);
                    
                    return dp[i][prv]=min(change,noChange);
                }
                else
                {
                    if(arr2[i]>arr1[i-1]&&arr1[i]>arr2[i-1]){
                        int change = 1+help(i+1,1,arr1,arr2,dp);
                        return dp[i][prv]=change;
                    }
                    else
                        return dp[i][prv]= 1e9;
                }
            }
            else
            {
                if(arr1[i]>arr2[i-1]&&arr2[i]>arr1[i-1])
                {
                    int noChange = help(i+1,0,arr1,arr2,dp);
                    int change = 1e9;
                    
                    if(arr1[i]>arr1[i-1]&&arr2[i]>arr2[i-1])
                        change = 1+help(i+1,1,arr1,arr2,dp);
                    
                    return dp[i][prv]=min(change,noChange);
                }
                
                else{
                     if(arr1[i]>arr1[i-1]&&arr2[i]>arr2[i-1])
                     {
                         int change = 1+help(i+1,1,arr1,arr2,dp);
                         return dp[i][prv]=change;
                     }
                     
                    return dp[i][prv]=1e9;
                }
                    
            }
        }
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int x = help(0,0,nums1,nums2,dp);
        // cout<<x<<endl;
        if(x>=1e9)
            return -1;
        
        return x;
    }
};