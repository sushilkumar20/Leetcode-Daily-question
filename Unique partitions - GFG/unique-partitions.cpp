//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void help(int i, int target, vector<int> &curr, vector<vector<int>> &ans)
	{
	    
	    if(target==0)
	    {
	        ans.push_back(curr);
	        return;
	    }
	    
	    if(target<0)
	    return ;
	    
	    if(i==0)
	    return ;
	    
	    if(target>=i)
	    {
	        curr.push_back(i);
	        help(i,target-i,curr,ans);
	        curr.pop_back();
	        help(i-1,target,curr,ans);
	    }
	    else
	    help(i-1,target,curr,ans);
	}
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        
        
        
        vector<vector<int>> ans;
        
        vector<int> curr;
        
        help(n,n,curr, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends