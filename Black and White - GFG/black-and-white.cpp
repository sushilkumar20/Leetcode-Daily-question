//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
    long long ans = 0;
    int mod = 1e9+7;
    
    vector<pair<int,int>> dir = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int cnt = 0;
            
            for(int k=0;k<dir.size();k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;
                
                if(x>=0&&x<N&&y>=0&&y<M)
                cnt++;
            }
            
            ans = (ans+(N*M-cnt))%mod;
            
        }
    }
    
    return ans-N*M;
}