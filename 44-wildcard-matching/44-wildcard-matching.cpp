class Solution {
public:
    
    bool help(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
      // cout<<i<<" "<<j<<endl;
        
        if(i<0&&j<0) return true;
        
        if(i>=0&&j<0) return false;
        
        if(i<0)
        {
            while(j>=0)
            {
                if(p[j]!='*')
                    return false;
                j--;
            }
            
            return true;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==p[j]||p[j]=='?')
            return dp[i][j] = help(i-1,j-1,s,p,dp);
        else if(p[j]=='*')
        {
            return dp[i][j] = (help(i-1,j,s,p,dp)|help(i,j-1,s,p,dp));
        }
        else
            return dp[i][j] = false;
        
    }
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return help(s.size()-1,p.size()-1,s,p,dp);
    }
};