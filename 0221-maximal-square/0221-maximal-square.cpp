class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n=  matrix.size();
        int m = matrix[0].size();
        int mx =0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(matrix[i-1][j-1]=='1')
                    {
                       dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                        
                        mx=max(mx,dp[i][j]);
                    }
                    
                }
                
            }
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return mx*mx;
    }
};