class Solution {
public:
    int help(int i, int j, int k,vector<int>&nums1,vector<int>&nums2,vector<vector<vector<int>>> &dp)
    {
        
        if(i==nums1.size()||j==nums2.size())
        {
            if(k)
                return 0;
            return -1*1e4;
        }
        
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        return dp[i][j][k]=max({nums1[i]*nums2[j]+help(i+1,j+1,1,nums1,nums2,dp),help(i+1,j,k,nums1,nums2,dp),help(i,j+1,k,nums1,nums2,dp)});
    }
    
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<vector<int>>> dp(nums1.size(),vector<vector<int>>(nums2.size(),vector<int>(2,-1)));
        
        // cout<<dp[0][0][0]<<endl;
        return help(0,0,0,nums1,nums2,dp);
    }
};