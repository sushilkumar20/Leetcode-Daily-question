class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        
        maze[entrance[0]][entrance[1]]='+';
        
        int tm = 0;
        while(q.size())
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                auto z = q.front();
                q.pop();
                int x = z.first;
                int y = z.second;
                // cout<<x<<" "<<y<<endl;
                
                if(x==entrance[0]&&y==entrance[1])
                {
                    if(x-1>=0&&maze[x-1][y]!='+')
                    {
                        q.push({x-1,y});
                        maze[x-1][y]='+';
                    }
                    
                    if(x+1<maze.size()&&maze[x+1][y]!='+')
                    {
                        q.push({x+1,y});
                        maze[x+1][y]='+';
                    }
                    
                    if(y-1>=0&&maze[x][y-1]!='+')
                    {
                        q.push({x,y-1});
                        maze[x][y-1]='+';
                    }
                    
                    if(y+1<maze[0].size()&&maze[x][y+1]!='+')
                    {
                        q.push({x,y+1});
                        maze[x][y+1]='+';
                    }
                    
                    continue;
                    
                }
                if(x-1<0||y-1<0||x+1>=maze.size()||y+1>=maze[0].size())
                {
                   
                    return tm;
                }
                else
                {
                    if(maze[x+1][y]!='+')
                    {
                        q.push({x+1,y});
                        maze[x+1][y]='+';
                    }
                    
                    if(maze[x-1][y]!='+')
                    {
                        q.push({x-1,y});
                        maze[x-1][y]='+';
                    }
                    
                    if(maze[x][y+1]!='+')
                    {
                        q.push({x,y+1});
                        maze[x][y+1]='+';
                    }
                    if(maze[x][y-1]!='+')
                    {
                        q.push({x,y-1});
                        maze[x][y-1]='+';
                    }
                }
                
            }
            
            tm++;
        }
        
        return -1;
    }
};