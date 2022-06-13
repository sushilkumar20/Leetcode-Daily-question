class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=  triangle.size();
        vector<vector<int>> dp(n,vector<int>(n));
        
        dp[0][0] = triangle[0][0];
        
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j-1>=0)
                {
                    if(j<triangle[i-1].size())
                    dp[i][j] = min(dp[i-1][j-1]+triangle[i][j],dp[i-1][j]+triangle[i][j]);
                    else
                    {
                        dp[i][j] = dp[i-1][j-1]+triangle[i][j];
                    }
                }
                else
                {
                    dp[i][j] = dp[i-1][j]+triangle[i][j];
                }
            }
        }
        
       
        int mn =INT_MAX;
        
       
            for(int j=0;j<n;j++)
            {
                mn = min(mn,dp[n-1][j]);
            }
           // cout<<endl;
        
        return mn;
        
    }
};