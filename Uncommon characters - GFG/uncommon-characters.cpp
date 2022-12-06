//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            
            map<char,int>mp;
            
            for(auto i:A)
            mp[i]=1;
            
            for(auto i:B){
                if(mp[i]==1)
                {
                    mp[i]=2;
                }
                else if(mp[i]==0)
                {
                    mp[i]=3;
                }
            }
            
            string ans = "";
            
            for(auto i:mp)
            {
                if(i.second!=2)
                ans+=i.first;
            }
            
            if(ans.size()==0)
            return "-1";
            return ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends