class Solution {
public:
    bool winnerSquareGame(int n) {
        
        vector<int> dp(n+1,0);
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                if(dp[i-j*j]==false)
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};