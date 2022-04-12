class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>> brr(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int o=0;
                int z=0;
                
                if(i>0)
                {
                    if(board[i-1][j]==0)
                        z++;
                    else
                        o++;
                }
                
                if(j>0)
                {
                    if(board[i][j-1]==0)
                        z++;
                    else
                        o++;
                }
                
                if(i<n-1)
                {
                     if(board[i+1][j]==0)
                        z++;
                    else
                        o++;
                }
                
                if(j<m-1)
                {
                     if(board[i][j+1]==0)
                        z++;
                    else
                        o++;
                }
                
                if(i-1>=0&&j-1>=0)
                {
                    if(board[i-1][j-1]==0)
                        z++;
                    else
                        o++;
                }
                
                if(i-1>=0&&j+1<m)
                {
                     if(board[i-1][j+1]==0)
                        z++;
                    else
                        o++;
                }
                
                 if(i+1<n&&j+1<m)
                {
                     if(board[i+1][j+1]==0)
                        z++;
                    else
                        o++;
                }
                
                 if(i+1<n&&j-1>=0)
                {
                     if(board[i+1][j-1]==0)
                        z++;
                    else
                        o++;
                }
                
               
                if(o<2)
                    brr[i][j]=0;
                else if(o==2)
                {
                    brr[i][j]=board[i][j];
                }
                else if(o>3)
                {
                    brr[i][j] = 0;
                }
                else if(o==3)
                {
                    brr[i][j] = 1;
                }
                
            }
        }
        
       
        board=brr;
    }
};