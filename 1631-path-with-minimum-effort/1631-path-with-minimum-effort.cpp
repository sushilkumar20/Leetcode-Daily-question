class Solution {
public:
   
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dir ={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        pq.push({0,0,0});
        
        dis[0][0]=0;
        
        while(pq.size())
        {
            auto p =pq.top();
            pq.pop();
            
            int x = p[1];
            int y = p[2];
            
            if(dis[x][y]<p[0]) continue;
           // if(x==n-1&&y==m-1) return p[0];
           
            
            for(auto i:dir)
            {
                int x1 = x+i[0];
                int y1 = y+i[1];
                
                if(x1>=n||x1<0||y1>=m||y1<0)
                    continue;
                
                if(dis[x1][y1]>max(p[0],abs(heights[x][y]-heights[x1][y1]))){
                    dis[x1][y1]=max(p[0],abs(heights[x][y]-heights[x1][y1]));
                    pq.push({dis[x1][y1],x1,y1});
                }
            }
        }
        
        return dis[n-1][m-1];
    }
};