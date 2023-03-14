//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
        int help(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
        {
            
            if(i>j)
            return 0;
            
            if(dp[i][j]!=-1)
            return dp[i][j];
            
            
            int mxCost = 0;
            
            for(int k=i;k<=j;k++)
            {
                int cost = arr[i-1]*arr[k]*arr[j+1] + help(i,k-1,arr,dp) + help(k+1,j,arr,dp);
                
                mxCost = max(mxCost,cost);
            }
            
            
            return dp[i][j] = mxCost;
            
        }
        int maxCoins(int N, vector <int> &a)
        {
                // write your code here
                
                a.insert(a.begin(),1);
                a.push_back(1);
                vector<vector<int>> dp(a.size(),vector<int>(a.size(),-1));
                
                return help(1,a.size()-2,a,dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends