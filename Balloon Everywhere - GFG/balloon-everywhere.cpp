//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        
        string s1 = "balloon";
        
        map<char,int> mp;
        
        for(auto i:s)
        mp[i]++;
        
        int mx = s.size();
        
        for(auto i:s1)
        {
            // cout<<mp[i]<<" "<<i<<endl;
            if(i=='l'||i=='o')
            {
                mx=min(mx,mp[i]/2);
            }
            else
            mx=min(mx,mp[i]);
        }
        
        return mx;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends