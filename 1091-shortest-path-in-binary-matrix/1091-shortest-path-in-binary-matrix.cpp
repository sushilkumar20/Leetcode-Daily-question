class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
       if(grid[0][0]!=0||grid[n-1][n-1]!=0)
           return -1;
        
      queue<vector<int>> q;
        
        q.push({0,0,1});
        
        grid[0][0]=1;
        
        int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        while(!q.empty())
        {
            int size=q.size();
            
            while(size-->0)
            {
                vector<int> point=q.front();
                q.pop();
                
                if(point[0]==n-1&&point[1]==n-1)
                    return point[2];
                
                for(auto d:dir)
                {
                    int r=point[0]+d[0];
                    int c=point[1]+d[1];
                    
                    if(r >=0 &&c>=0 &&r<n&&c<n&&grid[r][c]==0)
                    {
                        q.push({r,c,point[2]+1});
                        grid[r][c]=1;
                    }
                }
                    
            }
            
            
        }
        
    return -1;
    }
    
};