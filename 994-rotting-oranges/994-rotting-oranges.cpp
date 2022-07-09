class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        
       
        int cntOrange =0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                
                if(grid[i][j]!=0)
                    cntOrange++;
            }
        }
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        int rottenOrange = 0;
         int day =0;
        
        while(q.size())
        {
            int k = q.size();
            
            rottenOrange +=k;
           // cout<<k<<endl;
            
            for(int i=0;i<k;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nx = x+dx[j];
                    int ny = y+dy[j];
                   
                    if(nx<0||ny<0||nx>=n||ny>=m)
                        continue;
                    if(grid[nx][ny]!=1)
                        continue;
                    grid[nx][ny] = 2;
                    
                    q.push({nx,ny});
                    // cout<<nx<<" kkkk"<<ny<<endl;
                }
            }
            
            if(q.size())
                day++;
                
        }
        
        //cout<<cntOrange<<" "<<rottenOrange<<endl;
        if(cntOrange==rottenOrange)
            return day;
        return -1;
    }
};