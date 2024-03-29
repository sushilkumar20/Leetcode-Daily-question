//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        
        int n = s.size();
        stack<char> st;
        
        for(int i=0;i<n;i++)
        {
            if(st.size()&&st.top()==s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        string ans = "";
        
        while(st.size())
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        if(ans.size())
        return ans;
        
        return "-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends