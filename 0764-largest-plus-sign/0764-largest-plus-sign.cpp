class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        
        vector<vector<int>> mat(n,vector<int>(n,1));
        
        for(int i=0;i<mines.size();i++)
        {
           mat[mines[i][0]][mines[i][1]]=0;
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>> lr(n,vector<int>(n,0));
        vector<vector<int>> rl(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    lr[i][j]=mat[i][j];
                }
                else
                {
                    if(mat[i][j]==1)
                        lr[i][j]+=(lr[i][j-1]+1);
                    else
                        lr[i][j]=0;
                }
            }
            
            for(int j=n-1;j>=0;j--)
            {
                if(j==n-1)
                {
                    rl[i][j]=mat[i][j];
                }
                else
                {
                    if(mat[i][j])
                        rl[i][j]+=(rl[i][j+1]+1);
                    else
                        rl[i][j]=0;
                }
            }
        }
        
         vector<vector<int>> ud(n,vector<int>(n,0));
         vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(i==0)
                {
                    ud[i][j]=mat[i][j];
                }
                else
                {
                    if(mat[i][j])
                        ud[i][j]+=(ud[i-1][j]+1);
                    else
                        ud[i][j]=0;
                }
            }
            
            for(int i=n-1;i>=0;i--)
            {
                if(i==n-1)
                {
                    dp[i][j]=mat[i][j];
                }
                else
                {
                    if(mat[i][j])
                        dp[i][j]+=(dp[i+1][j]+1);
                    else
                        dp[i][j]=0;
                }
            }
        }
        
        int mx = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0||i==n-1||j==n-1)
                {
                    if(mat[i][j])
                        mx=max(mx,1);
                    continue;
                }
                else
                {
                    if(mat[i][j])
                    {
                        int left = lr[i][j-1];
                        int right = rl[i][j+1];
                        int u = ud[i-1][j];
                        int d = dp[i+1][j];

                        mx=max(mx,1+min({left,right,u,d}));
                        // cout<<i<<" "<<j<<endl;
                        // cout<<left<<" "<<right<<" "<<u<<" "<<d<<endl;
                    }
                    
                }
            }
        }
        
        return mx;
    }
};