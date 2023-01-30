//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    
    int help(int node, int par,int lg, vector<int> graph[],vector<vector<int>> &dp)
    {
        if(dp[node][lg]!=-1)
        return dp[node][lg];
        
        if(par == -1)
        {
            int k = 1;
            for(auto i: graph[node])
            {
                k+=help(i,node,1,graph,dp);
            }
            
            int x = 0;
            
            for(auto i: graph[node])
            {
                x+=help(i,node,0,graph,dp);
            }
            
            return dp[node][lg] = min(x,k);
        }
        else
        {
            int k = 1;
            for(auto i: graph[node])
            {
                if(i!=par)
                k+=help(i,node,1,graph,dp);
            }
            
            int x = 0;
            
            for(auto i: graph[node])
            {
                  if(i!=par)
                x+=help(i,node,0,graph,dp);
            }
            
            if(lg==0)
            return dp[node][lg] = k;
            
            return dp[node][lg] = min(x,k);
        }
    }
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        
        vector<int> graph[N+1];
        
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<vector<int>> dp(N+1,vector<int>(2,-1));
        
        return help(1,-1,0,graph,dp);
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends