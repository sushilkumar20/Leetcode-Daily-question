//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int i, vector<int> &vis,vector<vector<int>> &adj, int x)
    {
        vis[i]=x;
        
        for(auto j:adj[i])
        {
            if(vis[j]==0)
            {
                dfs(j,vis,adj,x);
            }
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        
        vector<int> vis(V+1);
        
        int x = 1;
        int ans = 0;
        for(int i=1;i<=V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,vis,adj,x);
                
                bool ok =1;
                int cnt=0;
                for(int j=1;j<=V;j++)
                {
                    if(vis[j]==x)
                    {
                       cnt++;
                    }
                }
                
                
                for(int j=1;j<=V;j++)
                {
                    if(vis[j]==x)
                    {
                        //  cout<<adj[j].size()<<" "<<cnt<<endl;
                      if(adj[j].size()!=cnt-1)
                      {
                         
                          ok=0;
                      }
                    }
                }
                
                if(ok)
                ans++;
                
                x++;
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends