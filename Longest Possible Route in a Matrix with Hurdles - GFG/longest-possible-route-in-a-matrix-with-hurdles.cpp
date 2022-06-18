// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:

    void help(int x,int y, int xd, int yd, vector<vector<int>> &matrix, vector<vector<int>>vis, int curr, int &ans)
    {
        if(x>=matrix.size()||y>=matrix[0].size()||x<0||y<0||matrix[x][y]==0||vis[x][y]==1)
        return;
        
        if(x==xd&&y==yd)
        {
            ans=max(ans,curr);
            return;
        }
        
         vis[x][y]=1;
         help(x+1,y,xd,yd,matrix,vis,curr+1,ans);
         help(x-1,y,xd,yd,matrix,vis,curr+1,ans);
         help(x,y-1,xd,yd,matrix,vis,curr+1,ans);
         help(x,y+1,xd,yd,matrix,vis,curr+1,ans);
         vis[x][y]=0;



        
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        
        int n=matrix.size();
        int m= matrix[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int curr=0;
        int mx=-1;
        
        help(xs,ys,xd,yd,matrix,vis,curr,mx);
        return mx;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends