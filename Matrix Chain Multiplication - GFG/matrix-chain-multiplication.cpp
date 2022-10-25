//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int help(int i, int j, int arr[],vector<vector<int>> &dp)
    {
        if(i==j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int min_step = 1e9;
        
        for(int k=i;k<=j-1;k++)
        {
            int step = arr[i-1]*arr[k]*arr[j]+help(i,k,arr,dp)+help(k+1,j,arr,dp);
            min_step = min(min_step,step);
        }
        
        return dp[i][j] = min_step;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N));
        
        for(int i=N-1;i>=1;i--)
        {
            for(int j=i+1;j<N;j++)
            {
                int min_step = 1e9;
                
                for(int k=i;k<=j-1;k++)
                {
                    int step = arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    min_step = min(min_step,step);
                }
                dp[i][j] = min_step;
            }
        }
        
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends