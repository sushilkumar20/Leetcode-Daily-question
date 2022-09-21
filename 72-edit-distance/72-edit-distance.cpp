class Solution {
public:
    
    int help(int i, int j, string s1, string s2, vector<vector<int>> &dp)
    {
        if(i<0&&j<0)
            return 0;
        if(j<0)
            return i+1;
        
         if(i<0)
             return j+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = help(i-1,j-1,s1,s2,dp);
        else
        {
            // delete replace insert
            return dp[i][j]=min({1+help(i-1,j,s1,s2,dp),1+help(i-1,j-1,s1,s2,dp),1+help(i,j-1,s1,s2,dp)});
        }
    }
    int minDistance(string word1, string word2) {
        
        
        int n = word1.size();
        int m = word2.size();
        
        int i=n-1;
        int j=m-1;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(i,j,word1,word2,dp);
    }
};