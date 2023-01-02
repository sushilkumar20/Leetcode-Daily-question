//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isPalindrome(string &x)
    {
        int i=0;
        int j=x.size()-1;
        
        while(i<=j)
        {
            if(x[i]!=x[j])
            return 0;
            
            i++;
            j--;
        }
        
        return 1;
    }
    int help(int i, int j, string &s,vector<vector<int>> &dp)
    {
        if(i==j)
        return 0;
        if(i>j)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        int mn = INT_MAX;
        
        string x = "";
        
        for(int k=i;k<j;k++)
        {
            x+=s[k];
            if(isPalindrome(x))
            {
               
                mn=min(mn,1+help(k+1,j,s,dp));
            }
        }
        x+=s[j];
        if(isPalindrome(x))
        {
          return dp[i][j]=0;
        }
        return dp[i][j]=mn;
    }
    int palindromicPartition(string str)
    {
        // code here
        
        int n = str.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return help(0,n-1,str,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends