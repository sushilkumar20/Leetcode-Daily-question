// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isPos(int i, int color,vector<int>&vis, bool graph[101][101])
{
    for(int j=0;j<101;j++)
    {
        if(graph[i][j]==1)
        {
            if(vis[j]==color)
            return false;
        }
    }
    return true;
}
bool check(int i, int n, int m, vector<int> &vis,bool graph[101][101])
{
    if(i==n)
    return true;
    
    for(int j=1;j<=m;j++)
    {
        if(isPos(i,j,vis,graph))
        {
            vis[i]=j;
            if(check(i+1,n,m,vis,graph))
            return true;
            
            vis[i]=0;
        }
    }
    
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code her
    
    vector<int> vis(n,0);
    
    return check(0,n,m,vis,graph);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends