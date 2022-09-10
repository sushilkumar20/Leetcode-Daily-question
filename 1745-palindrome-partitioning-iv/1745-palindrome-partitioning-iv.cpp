class Solution {
public:
    bool checkPartitioning(string s) {
       
        int n = s.size();
        
         if(n==3)
            return true;
        
        if(n<3)
            return false;
        
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
        }
        
        for(int len = 2; len<=n;len++)
        {
            
            for(int i=0;i<=n-len;i++)
            {
                int j = i+len-1;
                
                if(len==2)
                {
                    dp[i][j] = s[i]==s[j];
                }
                else
                {
                    if(s[i]==s[j]&&dp[i+1][j-1])
                        dp[i][j]=1;
                }
            }
        }
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                if(dp[0][i]&&dp[i+1][j]&&dp[j+1][n-1])
                    return true;
            }
        }
        
        return false;
        
    }
};