class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        
        int n = matrix.size();
        
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                {
                    dp[i+1][j] = dp[i][j]+matrix[i][j];
                }
        }
        
        int mx = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            for(int l = i+1; l<=n;l++)
            {
                for(int j=0;j<m;j++)
                {
                    int val =0;
                    for(int k=j;k<m;k++)
                    {
                        val += dp[l][k] - dp[i][k];
                        
                        if(val==K)
                            return val;
                        
                        if(val<K)
                            mx=max(mx,val);
                    }
                    
                   
                }
            }
        }
        
        return mx;
    }
};