class Solution {
public:
    
    int help(int i, int k, string &s, vector<vector<int>> &dp)
    {
        if(k<=0)
            return 1e9;
        
        if(i>=s.size())
            return 1e9;
        
        if(s.size()-i<k)
            return 1e9;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        if(k==1)
        {
            int x = i;
            int j = s.size()-1;
            int cnt = 0;
            while(x<j)
            {
                if(s[x]!=s[j])
                    cnt++;
                
                x++;
                j--;
            }
            
            return dp[i][k] = cnt;
        }
        
        int cnt = 1e9;
        for(int j=i;j<s.size();j++)
        {
            int x = i;
            int y = j;
            
            int curr= 0;
            while(x<y)
            {
                curr+=(s[x]!=s[y]);
                x++;
                y--;
            }
            
            cnt = min(cnt, curr + help(j+1,k-1,s,dp));
            
        }
        
         return   dp[i][k] =cnt;
    }
    int palindromePartition(string s, int k) {
        
        int n = s.size();
        
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        
        return help(0,k,s,dp);
    }
};