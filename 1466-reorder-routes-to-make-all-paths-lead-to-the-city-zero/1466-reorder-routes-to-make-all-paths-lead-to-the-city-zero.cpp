class Solution {
public:
    void dfs(vector<int>graph[],vector<int>&vis,int &ans ,int node)
    {
        if(vis[node])
           return;
         vis[node]=1;
        
         vector<int> neighbour=graph[node];
        
         for(int i=0;i<neighbour.size();i++)
         {
              if(vis[abs(neighbour[i])]==0&&needsToPointInReverseDirection(neighbour[i]))
                 ans++;
             int k=abs(neighbour[i]);
             dfs(graph,vis,ans,k);
            
         }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<int> graph[n];
        
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(-1*connections[i][0]);
        }
        
        vector<int> vis(n,0);
        
        int ans=0;
       
        dfs(graph,vis,ans,0);
        
        return ans;
    }
       bool needsToPointInReverseDirection(int node)
       {
        if(node > 0) return true;
        return false;
       }
};