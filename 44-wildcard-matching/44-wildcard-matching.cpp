class Solution {
public:
    
    bool help(int i, int j, string &s, string &p, vector<vector<int>> &dp,vector<int>&arr)
    {
       
        if(i<0&&j<0)
            return true;
        
        if(i<0)
        {
            auto k = upper_bound(arr.begin(),arr.end(),j)-arr.begin();
            
            if(k==0)
            return true;
            
            return false;
        }
        if(j<0)
            return false;
        if(i<0)
            return false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==p[j]||p[j]=='?')
        {
            return dp[i][j] = help(i-1,j-1,s,p,dp,arr);
        }
        if(p[j]!='*')
        {
            return dp[i][j] =  false;
        }
        else
        {
           return dp[i][j] = (help(i,j-1,s,p,dp,arr)||help(i-1,j,s,p,dp,arr));
        }
        
    }
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<int> arr;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]!='*')
                arr.push_back(i);
        }
        return help(s.size()-1,p.size()-1,s,p,dp,arr);
    }
};