//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	int mod = 1e9+7;
	    long long help(int i, string &s, vector<int> &dp)
	    {
	        if(i==s.size())
	        return 1;
	        if(dp[i]!=-1)
	        return dp[i];
	        int cnt = 0;
	        
	        if(s[i]=='0')
	        return 0;
	        else if(i<s.size()-1&&stoi(s.substr(i,2))<=26)
	        { 
	            
	            return dp[i]=(help(i+1,s,dp)+help(i+2,s,dp))%mod;
	        }
	        else
	        return dp[i]=(help(i+1,s,dp))%mod;
	    }
		int CountWays(string str){
		    // Code here
		    
		    int  n = str.size();
		    vector<int> dp(n,-1);
		    return help(0,str,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends