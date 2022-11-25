//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    // grid[i][j]=2;
                }
            }
        }
        
        int ans = 0;
        
        vector<pair<int,int>> dirr = {{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size())
        {
            int x = q.size();
            
            
            for(int i=0;i<x;i++)
            {
                auto u = q.front();
                q.pop();
                int x = u.first;
                int y = u.second;
                
                for(auto d :dirr)
                {
                    int x1 = x+d.first;
                    int y1 = y+d.second;
                    
                    if(x1<0||y1<0||x1>=n||y1>=m)
                    continue;
                    
                    if(grid[x1][y1]!=1)
                    continue;
                    
                    // cout<<x1<<" "<<y1<<" "<<ans<<endl;
                    q.push({x1,y1});
                    grid[x1][y1]=2;
                    
                }
                
                
            }
            
            ans++;
        }
        
        // bool ok = true;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        
        
        if(ans==0)
        return 0;
        return ans-1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends