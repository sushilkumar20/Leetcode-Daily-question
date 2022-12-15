//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void help(int i, string &s, string &curr, set<string>&st, vector<int> &frq)
	    {
	        if(curr.size()==s.size())
	        {
	            st.insert(curr);
	            return;
	        }
	        
	        for(int j=0;j<s.size();j++)
	        {
	            if(frq[j]==0)
	            {
	                frq[j]=1;
	                curr+=s[j];
	                help(j,s,curr,st,frq);
	                frq[j]=0;
	                curr.pop_back();
	            }
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    sort(s.begin(),s.end());
		    
		    string curr = "";
		    
		    int n = s.size();
		    
		    vector<int> frq(n);
		    
		    set<string> st;
		    
		    help(0,s,curr,st,frq);
		    
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