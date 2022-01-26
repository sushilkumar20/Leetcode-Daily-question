// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        string ans="";
        
       
        
        stack<char>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==']')
            {
                string k="";
                
                while(st.size()&&st.top()!='[')
                {
                    k=st.top()+k;
                    st.pop();
                }
                
                st.pop();
                string n="";
                
               while (!st.empty() && isdigit(st.top())) {
                n = st.top() + n;
                st.pop();
            }
            
            int num=stoi(n);
            
            string rep="";
            for(int i=0;i<num;i++)
            rep+=k;
            
            for(int i=0;i<rep.size();i++)
            st.push(rep[i]);
            }
            else
            st.push(s[i]);
        }
        
     while(st.size())
     {
         ans=st.top()+ans;
         st.pop();
     }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends