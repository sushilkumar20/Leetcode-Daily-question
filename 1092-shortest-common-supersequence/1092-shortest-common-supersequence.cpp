class Solution {
public:
//     int help(int i, int j, string str1, string str2, vector<vector<int>>&dp)
//     {
//         if(i<0||j<0)
//             return 0;
//         if(dp[i+1][j+1]!=-1)
//             return dp[i+1][j+1]; 
        
//         if(str1[i]==str2[j])
//             return dp[i+1][j+1] = 1+help(i-1,j-1,str1,str2,dp);
//         else
//             return dp[i+1][j+1] = max(help(i-1,j,str1,str2,dp),help(i,j-1,str1,str2,dp));
//     }
    string shortestCommonSupersequence(string str1, string str2) {
        
        string ans = "";
        
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    // cout<<dp[i][j]<<" ";
                }
                else
                {
                    int x1 = dp[i-1][j];
                    int y1 =dp[i][j-1];
                    
                    dp[i][j] = max(x1,y1);
                    // cout<<dp[i][j]<<" ";
                }
            }
            // cout<<endl;
        }
        
        // string ans = "";
        
        int i=n;
        int j=m;
        
        while(i>0&&j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans+=str1[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    ans+=str1[i-1];
                    i--;
                }
                else
                {
                     ans+=str2[j-1];
                     j--;
                }
            }
        }
        
        while(i>0)
        {
             ans+=str1[i-1];
             i--;
        }
        
        while(j>0)
        {
             ans+=str2[j-1];
             j--;
        }
        
        reverse(ans.begin(),ans.end());
        // cout<<ans.size()<<endl;
        return ans;
    }
};