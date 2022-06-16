class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
        string s1=s;
        
        reverse(s1.begin(),s1.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int mx =0;
        string ans ="";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==s1[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(mx<dp[i][j])
                    {
                        string s2=s.substr(i-dp[i][j],dp[i][j]);
                        string s3=s2;
                        reverse(s3.begin(),s3.end());
                        if(s2==s3)
                        {
                            ans=s.substr(i-dp[i][j],dp[i][j]);
                            mx=dp[i][j];
                        }
                    }
                    
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        
       return ans;
    }
};