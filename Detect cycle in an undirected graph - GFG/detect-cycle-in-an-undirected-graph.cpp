//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V,-1);
        
        queue<int> q;
        
       
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==-1)
            {
                // cout<<i<<endl;
                q.push(i);
                vis[i]=i;
                while(q.size())
                {
                    int u = q.front();
                    q.pop();
                    for(auto v : adj[u])
                    {
                        if(vis[v]!=-1&&vis[u]!=v){
                            //  cout<<v<<" "<<u<<endl;
                        return 1;
                        }
                        
                        if(vis[v]==-1)
                        q.push(v);
                        // cout<<v<<" "<<u<<endl;
                        vis[v]=u;
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends