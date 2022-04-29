class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&vis)
    {
        for(auto i:graph[node])
        {
            if(vis[i]==-1)
            {
                vis[i]=(vis[node]+1)%2;
                if(!dfs(i,graph,vis))
                    return false;
            }
            else
            {
                if(vis[i]==vis[node])
                    return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> vis(n,-1);
        
       
        
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                vis[i]=0;
                if(!dfs(i,graph,vis))
                    return false;
            }

               
        }
       
        
        return true;
    }
};