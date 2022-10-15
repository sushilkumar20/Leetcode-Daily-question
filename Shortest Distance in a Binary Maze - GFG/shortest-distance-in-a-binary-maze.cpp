//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        vector<vector<int>> dist = grid;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            dist[i][j]=1e9;
        }
        
        if(grid[source.first][source.second]==0)
        return -1;
        queue<pair<int,int>> q;
        
        dist[source.first][source.second] = 0;
        
        q.push(source);
        
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        
        while(q.size())
        {
            int x = q.front().first;
            int y = q.front().second;
            int d = dist[x][y];
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int x1 = x + dir[i].first;
                int y1 = y + dir[i].second;
                
                if(x1<0||x1>=grid.size()||y1<0||y1>=grid[0].size()||grid[x1][y1]==0)
                continue;
                
                if(dist[x1][y1]>d+1)
                {
                    dist[x1][y1] = d+1;
                    q.push({x1,y1});
                }
            }
            
        }
        
        if(dist[destination.first][destination.second]>=1e9)
        return -1;
        
        return dist[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends