class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        string ans ="";
        int mx=0;
        
        for(int i=0;i<n;i++)
        {
            ans=s[i];
            mx=1;
            
            dp[i][i]=1;
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                ans=s.substr(i,2);
                mx=2;
            }
        }
        
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                int j = i+k-1;
                //cout<<i<<" "<<j<<endl;
                if(s[i]==s[j]&&dp[i+1][j-1])
                {
                    dp[i][j]=1;
                    
                    if(mx<k)
                    {
                        mx=k;
                       
                        ans=s.substr(i,k);
                    }
                }
            }
        }
        
        return ans;
    }
};