//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    int n = A.size();
		    string ans = "";
		    
		    queue<char> q;
		    
		    map<char,int> mp;
		    
		    for(int i=0;i<n;i++)
		    {
		        mp[A[i]]++;
		        q.push(A[i]);
		        
		        while(q.size()&&mp[q.front()]>1)
		        {
		            q.pop();
		        }
		        
		        if(q.size())
		        {
		            ans+=q.front();
		        }
		        else
		        ans += '#';
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends