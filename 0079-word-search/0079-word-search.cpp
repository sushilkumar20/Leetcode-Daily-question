class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>& board,string &s, int n)
    {
         if(s.size()==n)
            return true;
       // cout<<i<<" "<<j<<endl;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=s[n])
            return false;
        
        board[i][j]='-1';
        
        bool ok = (dfs(i+1,j,board,s,n+1)||dfs(i-1,j,board,s,n+1)||dfs(i,j+1,board,s,n+1)||dfs(i,j-1,board,s,n+1));
        
        board[i][j]=s[n];
        return ok;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        if(word.size()>board.size()*board[0].size())
            return false;
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(word[0]==board[i][j])
                {
                    string s="";
                    if(dfs(i,j,board,word,0))
                        return true;
                }
            }
        }
        
        return false;
    }
};