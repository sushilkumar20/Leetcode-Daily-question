//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int i, vector<int> graph[], vector<int> &vis)
    {
        vis[i]=1;
        
        for(auto child:graph[i])
        {
            if(vis[child]==0)
            {
                dfs(child,graph,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<int> graph[V];
        
        int cnt =0;
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)
                {
                   graph[i].push_back(j);
                   graph[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,graph,vis);
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends