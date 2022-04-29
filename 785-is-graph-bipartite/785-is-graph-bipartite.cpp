class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> vis(n,-1);
        
        queue<int> q;
        
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                q.push(i);
                vis[i]=0;
            }

                while(q.size())
                {
                    int k=q.front();
                    q.pop();

                    for(auto node :graph[k])
                    {
                        if(vis[node]==-1)
                        {
                            if(vis[k]==1)
                                vis[node]=0;
                            else
                                vis[node]=1;
                            q.push(node);
                        }
                        else
                        {
                            if(vis[node]==vis[k])
                                return false;
                        }
                    }
                }
        }
       
        
        return true;
    }
};