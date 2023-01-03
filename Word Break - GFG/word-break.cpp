//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
   bool help(int i, string &A, set<string>&st,vector<int> &dp)
   {
       if(i==A.size())
       return 1;
       if(dp[i]!=-1)
       return dp[i];
       bool ok =0;
       string x = "";
       for(int j=i;j<A.size();j++)
       {
           x+=A[j];
           
           if(st.find(x)!=st.end())
           ok=(ok||help(j+1,A,st,dp));
       }
       
       return dp[i]=ok;
   }
    int wordBreak(string A, vector<string> &B) {
        //code here
        
        set<string> st;
        
        for(auto str:B)
        {
            st.insert(str);
        }
        
        int  n = A.size();
        vector<int> dp(n,-1);
        return help(0,A,st,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends