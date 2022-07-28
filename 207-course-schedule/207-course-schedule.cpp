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
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        
        int cnt=0;
        
        queue<int> q;
        
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        
        while(q.size())
        {
            int u = q.front();
            q.pop();
            cnt++;
            for(auto v:adj[u])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                    q.push(v);
            }
        }
        
       // cout<<cnt<<endl;
        if(cnt==numCourses)
            return true;
        
        return false;
    }
};