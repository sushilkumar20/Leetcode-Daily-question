class Solution {
public:
    string countAndSay(int n) {
        
        string s= "1";
        
        if(n==1)
            return s;
        
        //vector<string> dp(n+1);
        //dp[1] =s;
        s="11";
        for(int i=3;i<=n;i++)
        {
            string p="";
            int cnt=1;
           // char x = s[0];
            
            for(int j=1;j<s.size();j++)
            {
                
                if(s[j]==s[j-1])
                {
                    cnt++;
                    
                }
                else
                {
                    p+=to_string(cnt);
                    p+=s[j-1];
                    cnt=1;
                    
                }
                
                
            }
            
            p+=to_string(cnt)+s[s.size()-1];
            s=p;
        }
        
        return s;
    }
};