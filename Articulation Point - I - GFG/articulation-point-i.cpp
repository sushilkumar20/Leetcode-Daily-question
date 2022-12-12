//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution {
  public:
    
    void dfs(int node, int par, vector<int>&vis, vector<int>&inTime, vector<int>&lowInTime, vector<int> adj[], vector<int> &articulationPoint, int &timer)
    {
        //cout<<node<<endl;
        vis[node] = 1;
        inTime[node] = timer;
        lowInTime[node] = timer;
        timer++;
        int child =0;
        for(auto it:adj[node])
        {
            if(it==par)
            {
                continue;
            }
            
            if(vis[it]==0)
            {
                dfs(it,node,vis,inTime,lowInTime,adj,articulationPoint,timer);
                
                lowInTime[node] = min(lowInTime[node],lowInTime[it]);
                
                if(par !=-1&& lowInTime[it]>=inTime[node])
                {
                    articulationPoint[node] = 1;
                }
                
                child++;
            }
            else
            {
                lowInTime[node] = min(lowInTime[node],inTime[it]);
            }
        }
        if(par==-1&&child>1)
         articulationPoint[node] = 1;
        
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        vector<int> vis(V,0);
        vector<int> inTime(V,0);
        vector<int> lowInTime(V,0);
        
        vector<int> articulationPoint(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                int timer = 1;
                dfs(i,-1,vis,inTime,lowInTime,adj,articulationPoint,timer);
            }
        }
        
        vector<int> ans;
        
        for(int i=0;i<V;i++)
        {
            if(articulationPoint[i])
            ans.push_back(i);
        }
        
        if(ans.size()==0)
        ans.push_back(-1);
        //cout<<ans.size()<<endl;
        return ans;
    }
};

//{ Driver Code Starts.

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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends