class Solution {
public:
    bool bfs(int i,int j, vector<vector<int>>& heights,int mid)
    {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>> q;
        
        vector<vector<int>> dir ={{1,0},{0,1},{-1,0},{0,-1}};
        
        q.push({0,0});
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0]=1;
        while(q.size())
        {
            auto p = q.front();
            q.pop();
            
            
            int x = p.first;
            int y = p.second;
            
            if(x==n-1&&y==m-1)
                return true;
            
            for(auto &d :dir)
            {
                int x1=x+d[0];
                int y1=y+d[1];
                
                if(x1<0||y1<0||x1>=n||y1>=m)
                {
                    continue;
                }
                
             
                
                if(vis[x1][y1])
                    continue;
                if(abs(heights[x][y]-heights[x1][y1])>mid)
                    continue;
                
                 if(x1==n-1&&y1==m-1)
                  return true;
                vis[x1][y1]=1;
                q.push({x1,y1});
                
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int low =0;
        int high =1e9;
        int ans=1e9;
       
        cout<<bfs(0,0,heights,1)<<endl;
        while(low<=high){
            
            int mid =(low+high)/2;
            if(bfs(0,0,heights,mid))
            {
                ans =  min(mid,ans);
                high = mid-1;
            }
            else
            {
                low =  mid+1;
            }
        }
        
        return ans;
    }
};