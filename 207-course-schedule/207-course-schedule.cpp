class Solution {
public:
    
    bool dfs(int node, vector<int>&dfsV, vector<int>&vis, vector<int> adj[])
    {
        //cout<<node<<endl;
        vis[node] = 1;
        dfsV[node]=1;
        for(auto child:adj[node])
        {
           // cout<<child<<endl;
            if(!vis[child])
            {
                if(dfs(child,dfsV,vis,adj))
                    return true;
            }
            else if(dfsV[child])
                return true;
        }
        
        dfsV[node] = 0;
        
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        int n = prerequisites.size();
        
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> vis(numCourses,0);
         vector<int> dfsV(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            { 
                 //cout<<i<<endl;
                 if(dfs(i,dfsV,vis,adj)){
                     cout<<i<<endl;
                     return false;
                 }
            }
           
        }
        
        return true;
    }
};