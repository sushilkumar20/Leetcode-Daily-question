class Solution {
public:
    bool isPos(int col,int row,vector<string>&curr)
    {
        int i=row-1;
        int j=col-1;
        
        while(i>=0&&j>=0)
        {
            if(curr[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        
        i=row;
        j=col-1;
        
        while(j>=0)
        {
             if(curr[i][j] == 'Q')
                return false;
            
            j--;
        }
        
        i=row+1;
        j=col-1;
        
        while(i<curr.size()&&j>=0)
        {
             if(curr[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    void help(int col, int n, vector<vector<string>> &ans, vector<string> &curr)
    {
        if(col==n)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int row =0; row<n;row++)
        {
            if(isPos(col,row,curr))
            {
                curr[row][col]='Q';
                help(col+1,n,ans,curr);
                curr[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        
        vector<string> curr(n,string(n,'.'));
        
        help(0,n,ans,curr);
        
        return ans;
    }
};