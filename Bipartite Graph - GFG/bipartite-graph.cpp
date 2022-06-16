// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    bool dfs(int u, vector<int>& vis, vector<int>adj[])
    {
        for(auto v:adj[u])
        {
            if(vis[v]==0)
            {
                vis[v] =(3-vis[u]);
                bool ok=dfs(v,vis,adj);
                if(!ok)
                return false;
            }
            else
            {
                if(vis[v]==vis[u])
                return false;
            }
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int>vis(V,0);
	    
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	    vis[i]=1;
	   
	    if(!dfs(i,vis,adj))
	    return false;
	        }
	    }
	    
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends