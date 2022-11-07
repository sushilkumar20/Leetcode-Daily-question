class Solution {
public:
    int help(int i, int j,string &s, string &s1, vector<vector<int>>&dp)
    {
        if(i==s.size()||j==s1.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s1[j])
            return dp[i][j] = 1+help(i+1,j+1,s,s1,dp);
        
        return dp[i][j] = max(help(i+1,j,s,s1,dp),help(i,j+1,s,s1,dp));
    }
    int minInsertions(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        string s1 = s;
        
        reverse(s1.begin(),s1.end());
        
        int longestPalindromicSubsequence = help(0,0,s,s1,dp);
        // cout<<longestPalindromicSubsequence<<endl;
        return n-longestPalindromicSubsequence;
    }
};