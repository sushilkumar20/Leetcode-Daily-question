//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int help(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
  {
      if(i>=s1.size()||j>=s2.size())
      return 0;
      if(dp[i][j]!=-1)
      return dp[i][j];
      
      if(s1[i]==s2[j])
      return dp[i][j] = 1+help(i+1,j+1,s1,s2,dp);
      else
      return dp[i][j] = max(help(i+1,j,s1,s2,dp),help(i,j+1,s1,s2,dp));
  }
    int countMin(string s1){
    //complete the function here
    
    int n = s1.size();
    string s2 = s1;
    
    reverse(s2.begin(),s2.end());
    
    vector<vector<int>> dp(n,vector<int>(n,-1));
    
    int x = help(0,0,s1,s2,dp);
    
    return s1.size()-x;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends