//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
const int MOD = 1e9 + 7;
    int totalWays(int n, vector<int>capacity) {
        // code here
        
          sort(capacity.begin(), capacity.end());
        long long ways = 1;
        for(int j = 0; j < n; j++) ways = (ways * (capacity[j] - j)) % MOD;
        return ways;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends