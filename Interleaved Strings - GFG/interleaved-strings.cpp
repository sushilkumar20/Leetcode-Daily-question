//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool help(int i, int j,  int k, string &s1, string &s2, string &s3,vector<vector<int>>&dp)
    {
        if(k==s3.size())
        return 1;
        
        if(i==s1.size())
        return s2.substr(j)==s3.substr(k);
        
        if(j==s2.size())
        return s1.substr(i)==s3.substr(k);
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        bool ans = 0;
        if(s1[i]==s3[k])
        {
            ans = ( ans|| help(i+1,j,k+1,s1,s2,s3,dp));
        }
        
        if(s2[j]==s3[k])
        {
           ans = (ans || help(i,j+1,k+1,s1,s2,s3,dp));
        }
        // else
        // {
        //     return (help(i+1,j,k,s1,s2,s3,dp)||help(i,j+1,k,s1,s2,s3,dp));
        // }
        
        return dp[i][j] = ans;
        
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        vector<vector<int>> dp(A.size(),vector<int>(B.size(),-1));
        return help(0,0,0,A,B,C,dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends