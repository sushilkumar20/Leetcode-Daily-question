class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        vector<pair<int,int>> arr[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                arr[i].push_back(pair<int,int>{j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
                arr[j].push_back(pair<int,int>{i,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
        }
        
        vector<int> vis(n,0);
        vector<int> par(n,-1);
        vector<int> key(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        key[0]=0;
        int ans=0;
        while(pq.size()!=0)
        {
            int k=pq.top().second;
            
            pq.pop();
            
            if(vis[k])
                continue;
            
            vis[k]=true;
            
            for(auto i:arr[k])
            {
                int v=i.first;
                int w=i.second;
                
                if(vis[v]==0&&key[v]>w)
                {
                   
                    key[v]=w;
                    par[v]=k;
                    pq.push({w,v});
                }
            }
            
            
        }
        
        for(int i=0;i<n;i++)
        {
           // cout<<key[i]<<endl;
            ans+=key[i];
        }
        
        return ans;
    }
};