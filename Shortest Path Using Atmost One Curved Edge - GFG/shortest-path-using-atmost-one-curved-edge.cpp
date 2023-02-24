//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        
        vector<pair<int,pair<int,int>>> graph[n+1];
        
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],{edges[i][2],edges[i][3]}});
            graph[edges[i][1]].push_back({edges[i][0],{edges[i][2],edges[i][3]}});
        }
        
        set<pair<int,pair<int,int>>> pq;
        
        vector<pair<int,int>> dist(n+1);
        
        for(int i=1;i<=n;i++)
        {
            dist[i].first = 1e9;
            dist[i].second = 1e9;
        }

        pq.insert({0,{a,0}});
        
        dist[a].first=0;
        
        while(pq.size())
        {
            int x = (*pq.begin()).first;
            int u = (*pq.begin()).second.first;
            
            int tp = (*pq.begin()).second.second;
           
            pq.erase(pq.begin());
            for(auto v : graph[u])
            {
                int nd = v.first;
                int wt1 = v.second.first;
                int wt2 = v.second.second;
                
                
                if(tp==0)
                {
                     
                    if(dist[u].first+wt1<dist[nd].first)
                    {
                        
                        dist[nd].first = dist[u].first+wt1;
                        pq.insert({dist[nd].first,{nd,0}});
                    }
                    
                    if(dist[u].first+wt2<dist[nd].second)
                    {
                        dist[nd].second = dist[u].first+wt2;
                        pq.insert({dist[nd].second,{nd,1}});
                    }
                }
                else
                {
                     if(dist[u].second+wt1<dist[nd].second)
                    {
                        dist[nd].second = dist[u].second+wt1;
                        pq.insert({dist[nd].second,{nd,1}});
                    }
                }
            }
            
            
        }
        
        
       
        if( min(dist[b].first,dist[b].second)==1e9)
        return -1;
        
        return min(dist[b].first,dist[b].second);
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends