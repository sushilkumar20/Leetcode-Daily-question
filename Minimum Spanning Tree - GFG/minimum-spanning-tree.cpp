// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        
        
        
        vector<int> key(v,1e9);
        vector<int> mst(v,0);
        vector<int> par(v,-1);
        
        key[0]=0;
        
        
        for(int i=0;i<v-1;i++)
        {
            int mn=INT_MAX;
            int u;
            for(int j=0;j<v;j++)
            {
                if(mst[j]==0&&key[j]<mn)
                {
                    mn=key[j];
                    u=j;
                }
            }
            
            mst[u]=1;
            
            for(auto node:adj[u])
            {
                int k = node[0];
                int w = node[1];
                
               
                
                if(mst[k]==0&&key[k]>w)
                {
                   
                    key[k]=w;
                    par[k]=u;
                }
            }
            
        }
        
        int ans=0;
        
        for(int i=0;i<v;i++)
        ans+=key[i];
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends