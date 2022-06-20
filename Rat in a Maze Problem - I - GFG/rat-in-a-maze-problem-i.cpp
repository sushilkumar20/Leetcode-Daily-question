// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(int i,int j, int n, vector<string>&ans,string s, vector<vector<int>> &vis, vector<vector<int>> &m)
    {
        if(i>=n||j>=n||m[i][j]==0)
        return ;
        
        if(i==n-1&&j==n-1)
        {
            ans.push_back(s);
            return ;
        }
        
        vis[i][j]=1;
        if(i<n-1&&vis[i+1][j]==0)
        {
            s+='D';
            dfs(i+1,j,n,ans,s,vis,m);
            s.pop_back();
        }
        
        if(j<n-1&&vis[i][j+1]==0)
        {
            s+='R';
             dfs(i,j+1,n,ans,s,vis,m);
             s.pop_back();
        }
        
        if(i>0&&vis[i-1][j]==0)
        {
            s+='U';
             dfs(i-1,j,n,ans,s,vis,m);
             s.pop_back();
        }
        
         if(j>0&&vis[i][j-1]==0)
        {
            s+='L';
             dfs(i,j-1,n,ans,s,vis,m);
             s.pop_back();
        }
        
        vis[i][j]=0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<string> ans;
        if(m[n-1][n-1]==0)
        return ans;
        string s= "";
        dfs(0,0,n,ans,s,vis,m);
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends