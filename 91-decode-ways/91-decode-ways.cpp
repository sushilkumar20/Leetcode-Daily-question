class Solution {
public:
    
    int dp[101]={0};
    int help(string s ,int i )
    {
        if(i==s.size())
            return 1;
        int ans=0;
        if(dp[i]!=0) return dp[i];
        if(s[i]!='0')
            ans+=help(s,i+1);
        
        if(i+1<s.size()&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6')))
            ans+=help(s,i+2);
        
        dp[i]=ans;
        return ans;
    }
    int numDecodings(string s) {
        
       return  help(s,0);
    }
};