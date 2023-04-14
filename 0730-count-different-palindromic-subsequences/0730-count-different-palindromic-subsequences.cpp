class Solution {
public:
      int mod = 1e9+7;
    int dp[1001][1001][4];
    long long help(int i, int j,int alpha,string &s)
    {
       
        if(i>j)
            return 0;
        if(dp[i][j][alpha]!=-1)
            return dp[i][j][alpha];
        
        if(i==j)
            return s[i] == (alpha + 'a');
        
        if(s[i] == s[j] && s[i] == (alpha + 'a'))
        {
            int dv = 2;
            
            for(int k =0;k<4;k++)
                dv = (dv + help(i+1,j-1,k,s))%mod;
            
            return dp[i][j][alpha] = dv;
            
        }
        else
        {
            return dp[i][j][alpha] = (help(i+1,j,alpha,s) +  help(i,j-1,alpha,s) - help(i+1,j-1,alpha,s)+mod)%mod;
        }
    }
    int countPalindromicSubsequences(string s) {
        
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<1001;j++)
            {
                for(int k=0;k<4;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        int sum = 0;
        
        for(int i=0;i<4;i++)
        {
            sum = (sum+help(0,s.size()-1,i,s))%mod;
        }
         
        return sum;
    }
};