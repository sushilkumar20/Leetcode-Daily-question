//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    // int dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>> &vis)
    // {
    //     if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j]>=1e9)
    //     return 1e9;
        
    //     if(vis[i][j]!=-1)
    //     return vis[i][j];
        
    //     if(grid[i][j]==1)
    //     return vis[i][j]=0;
        
    //     vis[i][j] = 1e9;
    //     return vis[i][j] = 1+min({dfs(i+1,j,grid,vis),dfs(i-1,j,grid,vis),dfs(i,j+1,grid,vis),dfs(i,j-1,grid,vis)});
    // }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,1e9));
	    
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({i,j});
	                vis[i][j]=0;
	            }
	        }
	    }
	    
	    vector<pair<int,int>> dirr = {{1,0},{-1,0},{0,1},{0,-1}};
	    
	    while(q.size())
	    {
	        int x = q.front().first;
	        int y = q.front().second;
	        
	        q.pop();
	        
	        for(int i=0;i<dirr.size();i++)
	        {
	            int x1 = x+dirr[i].first;
	            int y1 = y+dirr[i].second;
	            
	            if(x1<0||y1<0||x1>=n||y1>=m)
	            {
	                continue;
	            }
	            
	            int d = vis[x][y]+1;
	            if(vis[x1][y1]>d)
	            {
	                vis[x1][y1]=d;
	                q.push({x1,y1});
	            }
	        }
	    }
	    
	    return vis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends