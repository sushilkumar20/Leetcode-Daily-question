//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        
        queue<pair<int,int>> q;
        int n= grid.size();
        int m = grid[0].size();
        
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    break;
                }
            }
            if(q.size())
            break;
        }
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        while(q.size())
        {
            auto tp = q.front();
            int x = tp.first;
            int y = tp.second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int x1 = x+dir[i].first;
                int y1 = y+dir[i].second;
                
                if(x1>=0&&x1<n&&y1>=0&&y1<m&&vis[x1][y1]==0&&grid[x1][y1]!=0)
                {
                    if(grid[x1][y1]==2)
                    return 1;
                    q.push({x1,y1});
                    
                    vis[x1][y1] = 1;
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends