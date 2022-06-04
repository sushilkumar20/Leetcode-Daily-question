class Solution {
public:
    bool pos(int col, int row, int n, vector<string> &cur)
    {
        int i = row-1;
        int j = col-1;
        
        while(i>=0&&j>=0)
        {
            if(cur[i][j] == 'Q') return false;
            
            i--;
            j--;
        }
        
        j=col-1;
        i=row;
        
        while(j>=0)
        {
            if(cur[i][j] == 'Q') return false;
            
            j--;
        }
        
        i = row+1;
        j = col-1;
        
        while(i<n&&j>=0)
        {
            if(cur[i][j] == 'Q') return false;
            
            i++;
            j--;
        }
        
        return true;
        
    }
    void help(int col, int n, vector<string>&cur, vector<vector<string>> &ans)
    {
        if(col == n){
            ans.push_back(cur);
            return;
        }
        //cout<<col<<" ";
        for(int row = 0; row<n; row++)
        {
            if(pos(col,row,n,cur))
            {
                cur[row][col] = 'Q';
                help(col+1,n,cur, ans);
                cur[row][col] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        
        vector<string> curr(n,string(n,'.'));
        
        
        help(0,n,curr,ans);
        
        return ans;
    }
};