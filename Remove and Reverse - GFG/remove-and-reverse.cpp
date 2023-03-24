//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        
        map<int,int> mp;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        int i = 0;
        int j = s.size()-1;
      
        bool ok = 1;
        while(i<j)
        {
            if(ok)
            {
                if(mp[s[i]]>1)
                {
                    mp[s[i]]--;
                    s[i]='*';
                    ok=0;
                    
                }
                
                i++;
            }
            else
            {
                 if(mp[s[j]]>1)
                {
                    mp[s[j]]--;
                    s[j]='*';
                    ok=1;
                    
                }
                
                j--;
            }
            
        }
        
        string ans = "";
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != '*')
            ans+=s[i];
        }
        
        if(!ok)
        {
            reverse(ans.begin(),ans.end());
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends