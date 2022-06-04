class Solution {
public:
    bool pos(int row, int col, int n, vector<string>&cur)
    {
        int i = row-1;
        int j = col-1;
        
        while(i>=0 && j>=0 )
        {
            if(cur[i][j] == 'Q')
                return false;
            
            i--;
            j--;
        }
        
        i=row;
        j = col-1;
        
        while(j>=0)
        {
            if(cur[i][j] == 'Q')
                return false;
            
            j--;
        }
        
        i=row+1;
        j=col-1;
            
            while(j>=0&&i<n)
            {
                if(cur[i][j] == 'Q')
                    return false;
                
                i++;
                j--;
            }
        
        return true;
    }
    void help(int col, int n, int &ans, vector<string> &cur)
    {
        if(col == n){
            ans++;
           
           // cout<<ans<<endl;
             return;
        }
        
        for(int row = 0;row<n;row++)
        {
            if(pos(row,col,n,cur))
            {
                //cout<<row<<" "<<col<<endl;
                cur[row][col] = 'Q';
                
                help(col+1,n,ans,cur);
                
                cur[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        
        int ans = 0;
        
        vector<string> cur(n, string(n,'.'));
        
        help(0,n,ans,cur);
        
        return ans;
    }
};