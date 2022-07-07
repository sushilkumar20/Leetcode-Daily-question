class Solution {
public:
    int dp[101][101];
    bool check(string s1, string s2, string s3)
    {
        int a=s1.size();
        int b=s2.size();
        int c=s3.size();
        
        if(s3.size()==0)
            return true;
        if(dp[a][b]!=-1)
        {
            return dp[a][b];
        }
        if(a>0&&s3[c-1]==s1[a-1])
        {
            if(check(s1.substr(0,a-1), s2.substr(0,b), s3.substr(0,c-1))){
                dp[a][b]=1;
              return true;
            }
         
        }
        
         if(b>0&&s3[c-1]==s2[b-1])
        {
            if(check(s1.substr(0,a), s2.substr(0,b-1), s3.substr(0,c-1))){
                dp[a][b]=1;
                return true;
            }
               
        }
             
        dp[a][b]=0;
        return false;
               
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.size()+s2.size()!=s3.size())
            return false;
        dp[0][0]=1;
        
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        dp[0][0]=1;
        return check( s1,  s2,  s3);
    }
};