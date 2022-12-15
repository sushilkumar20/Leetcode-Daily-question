//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void help(int i, string &s, set<string>&st)
	    {
	        if(i==s.size())
	        {
	            st.insert(s);
	            return;
	        }
	        
	        for(int j=i;j<s.size();j++)
	        {
	            swap(s[i],s[j]);
	            help(i+1,s,st);
	            swap(s[i],s[j]);
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    sort(s.begin(),s.end());
		    
		    set<string> st;
		    
		   
		    help(0,s,st);
		    
		    vector<string> ans;
		    
		    for(auto i = st.begin();i!=st.end();i++)
		    ans.push_back(*i);
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends