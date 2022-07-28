class Solution {
public:
    
    bool dfs(int node, vector<int>&color, vector<vector<int>>& graph)
    {
        //color[node] = 1;
        
        for(auto child:graph[node])
        {
            if(color[child]==-1)
            {
                color[child] = 3-color[node];
                if(!dfs(child,color,graph))
                    return false;
                    
            }
            else
            {
                if(color[child]==color[node])
                    return false;
            }
        }
        
        return true;
    }
    bool bfs(int node, vector<int>&color, vector<vector<int>>& graph)
    {
         int n= graph.size(); 
        
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while(q.size())
        {
            int u = q.front();
            q.pop();
        
            for(auto v:graph[u])
            {
                if(color[v]==-1)
                {
                    color[v] =(1+color[u])%2;
                    q.push(v);
                }
                else
                {
                    if(color[v]==color[u])
                        return false;
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n= graph.size(); 
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                //color[i] = 1;
                if(!dfs(i,color,graph))
                    return false;
            }
        }
        
        return true;
        
    }
};