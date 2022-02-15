// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
int  fun(vector<vector<int>>&cost,vector<int> &vis,int ind,int n)
{
    if(ind>=n)
    return 0;
    
   int ans=INT_MAX;
   
    bool ok=false;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans=min(ans,cost[ind][i]+fun(cost, vis,i,n));
            ok=true;
            
        }
    }
    
    vis[ind]=0;
    
    if(!ok)
    {
        return cost[ind][0];
    }
    
    return ans;
    
}
int total_cost(vector<vector<int>>cost){
    // Code her
    
    vector<int> vis(cost.size(),0);
    vis[0]=1;
    int curr=0;
    
    return fun(cost,vis,0,cost.size());
    
    
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends