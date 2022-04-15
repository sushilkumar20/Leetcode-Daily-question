class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<double> dis(n,0);
        
        vector<pair<int,double>> graph[n];
        
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        
        pq.push({1,start});
        
        dis[start]=1;
        
        while(pq.size())
        {
            auto p=pq.top();
            pq.pop();
            
            double d= p.first;
            int v=p.second;
           
            for(auto i:graph[v])
            {
                if(i.second*dis[v]>dis[i.first])
                {
                    dis[i.first]=i.second*dis[v];
                    pq.push({dis[i.first],i.first});
                }
            }
        }
        
        return dis[end];
    }
};